void setup_AsyncWebserver(){
  // Voordat we de webserver starten, moet je OTA opstarten, hier zonder user/pw
  AsyncElegantOTA.begin(&webserver);

  // Analoog gaan we de WebSerial opstarten, zodat je kan zien wat er gebeurt
  WebSerial.begin(&webserver);

  // Route for root / web page (controller)
  webserver.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html", String(), false, html_processorRoot);
  });

  // Route for Wifi Passwoord onderhoud
  webserver.on("/wificfg", HTTP_GET, [](AsyncWebServerRequest *request) {
    Print("Wifi config pagina");
    request->send(SPIFFS, "/index.html", String(), false, html_processorWifi);
  });

  // Opvangen als wifi data bewaard worden
  webserver.on("/wifisave", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Wifi connection parameters");
    on_wifisave(request);
    request->send(SPIFFS, "/index.html", String(), false, html_processorWifi);
  });

  // Route for strip configuratie
  webserver.on("/maintain_strip", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("strip configuratie opgeroepen");
    request->send(SPIFFS, "/maintain_strip.html", "text/html");
  });

  // Route voor getstrip.
  webserver.on("/getStrip", HTTP_GET, [](AsyncWebServerRequest *request) {
    //Println("getstrip binnen gekregen"); geen print want we krijgen er zo 10 binnen
    request->send(200, "text/plain", on_getstrip(request));
  });

  webserver.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/style.css", "text/plain");
  });
    webserver.on("/jquery-3.7.0.min.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/jquery-3.7.0.min.js", "text/javascript");
  });
  webserver.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/favicon.ico", "image/png");
  });


 // Verwerk als er op een knop wordt gedrukt
  webserver.on("/knop", HTTP_GET, [](AsyncWebServerRequest *request) {
    String IDknopString;
    uint16_t IDknop;
    // GET input1 value on <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
    if (request->hasParam(PARAM_output)) {
      IDknopString = request->getParam(PARAM_output)->value();
      IDknop = IDknopString.toInt();
    }
    else {
      IDknop = 0;
    }

    Print("knop= ");
    Println(IDknop);
    switch (IDknop) {
    case id_Modedo:  //mode
//      operationMode = buttonChangeUp(operationMode, -1, "mode", OPERATION_DESC_COUNT);
      break;
    case id_Modeup:
//      operationMode = buttonChangeUp(operationMode, +1, "mode", OPERATION_DESC_COUNT);
      break;
    //Save Config
    case id_SaveConfig:
      buttonChangeConfig();
//      distributeCommand(COMMAND_SETSAV, 0, 0, 0);
      break;
    //Restart
    case id_Restart:
      buttonChangeRestart();
      break;

    default:
      Println("Impossible IDknop");
      break;
    }  // einde switch
    
    request->send(200, "text/plain", "OK");

  });

  // Start server
  webserver.begin();
}