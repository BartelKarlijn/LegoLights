void setup_AsyncWebserver(){
  
  // voor de zekerheid de webserver stoppen, en op het eind weer opstarten
  webserver.end();

  // Analoog gaan we de WebSerial opstarten, zodat je kan zien wat er gebeurt
  // Nog wat code aan de Webserial toevoegen.
  WebSerial.begin(&webserver);

  WebSerial.onMessage([&](uint8_t *data, size_t len) {
      Serial.printf("Received %lu bytes from WebSerial: ", len);
      
      String WebSerialMessage = String((char*)data).substring(0, len);
      //transmit to Serial1
      Serial1.println(WebSerialMessage);
      Println("Message=" + WebSerialMessage);
      commandParts = decodeCommand(WebSerialMessage);
      executeCommand();
  
    });
  // run handleUpload function when any file is uploaded
  webserver.onFileUpload(on_fileUpload);
    
  // Route for root / web page (controller)
  webserver.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Root requested");
    request->send(SPIFFS, "/page_root.html", "text/html");
  });
  // -- file management
  webserver.on("/getfile", HTTP_GET, [](AsyncWebServerRequest * request){
    Println("file requested");
    on_file(request);
  });
  webserver.on("/getfileList", HTTP_GET, [](AsyncWebServerRequest * request){
    Println("fileList requested");
    request->send(200, "text/plain", listFiles(true));
  });
  webserver.on("/getfileStorage", HTTP_GET, [](AsyncWebServerRequest * request){
    Println("fileStorage requested");
    request->send(200, "text/plain", listStorage(true));
  });
  // -- Strip management
  webserver.on("/getfileLoad2Kring", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Strip settings ophalen voor kring");
    request->send(200, "text/plain", on_getfileLoad2Kring(request));
  });
  webserver.on("/getfileDefault2Kring", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Strip terug naar default zetten");
    request->send(200, "text/plain", on_getfileDefault2Kring(request));
  });
  webserver.on("/getfileSaveKring", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Strip settings bewaren voor kring");
    request->send(200, "text/plain", on_getfileSaveKring(request));
  });
  webserver.on("/getlistKringen", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", listKringen(true, on_getlistKringen(request)) );
  });
  webserver.on("/getStrip", HTTP_GET, [](AsyncWebServerRequest *request) {
    //Println("getstrip binnen gekregen"); geen print want we krijgen er zo 10 binnen
    request->send(200, "text/plain", on_getStrip(request));
  });
  webserver.on("/getSetStrip", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("setstrip binnen gekregen");
    request->send(200, "text/plain", on_getSetStrip(request));
  });
  //--------------------
  // -- led management--
  webserver.on("/ledAnimApply", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Animatie toepassen voor led");
    decodeRequestLed(request);
    request->send(200, "text/plain", settingledAnimApply());
  });
  webserver.on("/ledListAnim", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Led animaties tonen als option lijst");
    decodeRequestLed(request);
    request->send(200, "text/plain", settingledListAnim());
  });
  webserver.on("/ledSettingFileSave", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Alle Led settings bewaren in cfg file");
    decodeRequestLed(request);
    request->send(200, "text/plain", fileLedSaveSettings());
  });
  webserver.on("/ledValueGet", HTTP_GET, [](AsyncWebServerRequest *request) {
    //Println("getled binnen gekregen"); geen print want we krijgen er zo 10 binnen
    decodeRequestLed(request);
    request->send(200, "text/plain", ledValueGet());
  });
  webserver.on("/ledValueSet", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("setLed binnen gekregen");
    decodeRequestLed(request);
    request->send(200, "text/plain", ledValueSet());
  });
  //--------------------
  // -- andere dingen
  webserver.on("/restart", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Restarting ESP32 in 2sec");
    request->send(200, "text/plain", "Restarting ESP32 in 2sec");
    delay(2000);
    ESP.restart();
  });
  webserver.on("/wifisave", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Wifi connection parameters");
    on_wifisave(request);
    request->send(SPIFFS, "/page_wificfg.html", "text/html");
  });
  // everything else, currently only static files
  webserver.onNotFound([](AsyncWebServerRequest *request) {
    String RequestStr= request->url();
    Println("Request: "+RequestStr);
    String FileName = RequestStr.substring(0, RequestStr.indexOf("?"));

    for (int i = 0; i < MAX_WIFI_REQUEST; i++) {
      // checking if it's a valid file
      if (FileName.startsWith(validWifiRequest[i].reqPrefix) && FileName.endsWith(validWifiRequest[i].reqExt)) {
        if (validWifiRequest[i].iscmd) {
          // if it's a command, call the function
          String response = validWifiRequest[i].function(request);
          Println("X" + response);
          request->send(200, validWifiRequest[i].htmltype, response);
          return;
        }
       else if (SPIFFS.exists(FileName)) {
          // This should be a file.
          Println("Request: "+RequestStr);
          Println("Sending file " + FileName + " with type " + validWifiRequest[i].htmltype);
          request->send(SPIFFS, FileName, validWifiRequest[i].htmltype);
          return;
        } else {
          request->send(404, "text/plain", "File not found");
          return;
        }
      }
    } 

    Println("Wifi page not found, request: "+RequestStr);
    request->send(404, "text/plain", "Not found");
  });

  // Start server
  webserver.begin();
}