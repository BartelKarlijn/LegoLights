void setup_AsyncWebserver(){
  // Voordat we de webserver starten, moet je OTA opstarten, hier zonder user/pw
  AsyncElegantOTA.begin(&webserver);

  // Analoog gaan we de WebSerial opstarten, zodat je kan zien wat er gebeurt
  WebSerial.begin(&webserver);

  // Route for Wifi Passwoord onderhoud
  webserver.on(hdlWifiPWD, HTTP_GET, [](AsyncWebServerRequest *request) {
    Print("Wifi config pagina");
    request->send(SPIFFS, "/index.html", String(), false, html_processorWifi);
  });

  // Opvangen als wifi data bewaard worden
  webserver.on(hdlWifiSave, HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Wifi connection parameters");
    if (request->hasParam(PARAM_ssid)) {
      wifi_ssid = request->getParam(PARAM_ssid)->value();
    }
    else {
      wifi_ssid = "X";
    }
    if (request->hasParam(PARAM_pwd)) {
      wifi_pwd = request->getParam(PARAM_pwd)->value();
    }
    else {
      wifi_pwd = "X";
    }
    Print("ssid ");
    Println(wifi_ssid);
    Print("pwd ");
    Println(wifi_pwd);
    
    save_WIFIdatato_eeprom (); 
    Println("Wifi SSID and PWD saved; please reboot ESP32");
    request->send(SPIFFS, "/index.html", String(), false, html_processorWifi);
  });


  // Route for root / web page (controller)
  webserver.on(hdlRoot, HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html", String(), false, html_processorRoot);
  });
  webserver.on("/maintain_strip", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("strip configuratie opgeroepen");
    request->send(SPIFFS, "/maintain_strip.html", "text/html");
  });
  webserver.on("/getStrip", HTTP_GET, [](AsyncWebServerRequest *request) {
    //Println("getstrip binnen gekregen"); geen print want we krijgen er zo 10 binnen
    String kringString;
    int kringnr;
    String veldString;
    int veldnr;
    String answertoSend;
    // get parameter kring & veld  http://192.168.68.205/maintain_strip?kring=1?veld=hue1
    if (request->hasParam("kring")) {
      kringString = request->getParam("kring")->value();
      kringnr = kringString.toInt();
    }
    else {
      kringnr = 255;
    }
    if (request->hasParam("veld")) {
      veldString = request->getParam("veld")->value();
      veldnr = veldString.toInt();

      switch (veldnr)
      {
      case 1:  //we beginnen bij 1, zodat 0 een fout geeft
        answertoSend = kring[kringnr].desc;
        break;
      case 2:
        answertoSend = kring[kringnr].startled;
        break;
      case 3:
        answertoSend = kring[kringnr].stopled;
        break;
      case 4:
        answertoSend = kring[kringnr].hue1;
        break;
      case 5:
        answertoSend = kring[kringnr].sat1;
        break;
      case 6:
        answertoSend = kring[kringnr].bright1;
        break;
      case 7:
        answertoSend = kring[kringnr].hue2;
        break;
      case 8:
        answertoSend = kring[kringnr].sat2;
        break;
      case 9:
        answertoSend = kring[kringnr].bright2;
        break;
      case 10:
        answertoSend = kring[kringnr].hue3;
        break;
      case 11:
        answertoSend = kring[kringnr].sat3;
        break;
      case 12:
        answertoSend = kring[kringnr].bright3;
        break;
      case 13:
        answertoSend = kring[kringnr].hue4;
        break;
      case 14:
        answertoSend = kring[kringnr].sat4;
        break;
      case 15:
        answertoSend = kring[kringnr].bright4;
        break;
      case 16:
        answertoSend = kring[kringnr].every;
        break;
      case 17:
        answertoSend = kring[kringnr].timeon;
        break;
      case 18:
        answertoSend = kring[kringnr].timeoff;
        break;
      case 19:
        answertoSend = kring[kringnr].timeeffect;
        break;
      case 20:
        answertoSend = kring[kringnr].direction;
        break;
      case 21:
        answertoSend = kring[kringnr].effect;
        break;
      default:
        answertoSend = "error";
        break;
      }
    }
    else {
      answertoSend = "error";
    }
    request->send(200, "text/plain", answertoSend);
  });

  webserver.on(hdlCSS, HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/style.css", "text/plain");
  });
  webserver.on("/jquery-3.7.0.min.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/jquery-3.7.0.min.js", "text/javascript");
  });
  webserver.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/favicon.ico", "image/png");
  });


 // Verwerk als er op een knop wordt gedrukt
  webserver.on(hdlKnop, HTTP_GET, [](AsyncWebServerRequest *request) {
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