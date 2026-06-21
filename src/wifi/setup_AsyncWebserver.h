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
  //--------------------
  // -- huis management--
  webserver.on("/huisAnimApply", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Animatie toepassen voor huis");
    decodeRequestHuis(request);
    request->send(200, "text/plain", huisAnimApply());
  });
  webserver.on("/huisListAnim", HTTP_GET, [](AsyncWebServerRequest *request) {
    //Println("Huis animaties tonen als option lijst");
    decodeRequestHuis(request);
    request->send(200, "text/plain", huisListAnim());
  });
  webserver.on("/huisSettingFileLoad", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Alle Huis settings terug ophalen uit cfg file");
    decodeRequestHuis(request);
    request->send(200, "text/plain", fileHuisLoadSettings());
  });
  webserver.on("/huisSettingFileSave", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Alle Huis settings bewaren in cfg file");
    decodeRequestHuis(request);
    request->send(200, "text/plain", fileHuisSaveSettings());
  });
  webserver.on("/huisValueGet", HTTP_GET, [](AsyncWebServerRequest *request) {
    decodeRequestHuis(request);
    request->send(200, "text/plain", huisValueGet());
  });
  webserver.on("/huisValueSet", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("setLed binnen gekregen");
    decodeRequestHuis(request);
    request->send(200, "text/plain", huisValueSet());
  });
  //--------------------
  // -- led management--
  webserver.on("/ledAnimApply", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Animatie toepassen voor led");
    decodeRequestLed(request);
    request->send(200, "text/plain", ledAnimApply());
  });
  webserver.on("/ledAnimSaveMem", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("led Animatie actieve settings opslaan in geheugen");
    decodeRequestLed(request);
    request->send(200, "text/plain", ledAnimSaveMem());
  });
  webserver.on("/ledCopyFirstToAnim", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Copy default to animatie to all leds");
    decodeRequestLed(request);
    request->send(200, "text/plain", ledCopyFirstToAnim());
  });
  webserver.on("/ledSettingFileLoad", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Alle Led settings terug ophalen uit cfg file");
    decodeRequestLed(request);
    request->send(200, "text/plain", fileLedLoadSettings());
    ledLoadAnim();
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
  // -- rgb management--
  webserver.on("/rgbAnimApply", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Animatie toepassen voor rgb");
    decodeRequestRgb(request);
    request->send(200, "text/plain", rgbAnimApply());
  });
  webserver.on("/rgbAnimSaveMem", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("rgb Animatie actieve settings opslaan in geheugen");
    decodeRequestRgb(request);
    request->send(200, "text/plain", rgbAnimSaveMem());
  });
  webserver.on("/rgbCopyFirstToAnim", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Copy default to animatie to current anim");
    decodeRequestRgb(request);
    request->send(200, "text/plain", rgbCopyFirstToAnim());
  });
  webserver.on("/rgbSettingFileLoad", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Alle Rgb settings terug ophalen uit cfg file");
    decodeRequestRgb(request);
    request->send(200, "text/plain", fileRgbLoadSettings());
    rgbLoadAnim();
  });
  webserver.on("/rgbSettingFileSave", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Alle Rgb settings bewaren in cfg file");
    decodeRequestRgb(request);
    request->send(200, "text/plain", fileRgbSaveSettings());
  });
  webserver.on("/rgbValueGet", HTTP_GET, [](AsyncWebServerRequest *request) {
    //Println("getrgb binnen gekregen"); geen print want we krijgen er zo 10 binnen
    decodeRequestRgb(request);
    request->send(200, "text/plain", rgbValueGet());
  });
  webserver.on("/rgbValueSet", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("setRgb binnen gekregen");
    decodeRequestRgb(request);
    request->send(200, "text/plain", rgbValueSet());
  });

  //--------------------
  // -- andere dingen
  webserver.on("/restart", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Restarting ESP32 in 2sec");
    request->send(200, "text/plain", "Restarting ESP32 in 2sec");
    delay(2000);
    ESP.restart();
  });
  webserver.on("/showfirmware", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Show Firmware info");
    request->send(200, "text/plain", on_showfirmware());
  });
  webserver.on("/wifiScanNetworks", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Scanning Wifi networks");
    request->send(200, "text/plain", scanWifiNetworks());
  });
  webserver.on("/wifisave", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Wifi connection parameters");
    on_wifisave(request);
    request->send(SPIFFS, "/page_wificfg.html", "text/html");
  });
  // everything else, currently only static files
  webserver.onNotFound([](AsyncWebServerRequest *request) {
    String RequestStr= request->url();
    String FileName = RequestStr.substring(0, RequestStr.indexOf("?"));

    for (uint8_t i = 0; i < MAX_WIFI_REQUEST; i++) {
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
          Println("Sending " + FileName + ", type " + validWifiRequest[i].htmltype);
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