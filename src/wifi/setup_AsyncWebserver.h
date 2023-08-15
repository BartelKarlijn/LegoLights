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
  webserver.on(hdlpgStrip, HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("strip configuratie opgeroepen");
    request->send(SPIFFS, "/index.html", "text/plain");
  });
  webserver.on(hdlgetStrip, HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("getstrip binnen gekregen");
    String kringString;
    int kringnr;
    String veldString;
    int veldnr;
    String answertoSend;
    // get parameter kring & veld  http://192.168.68.205/maintain_strip?kring=1?veld=hue1
    if (request->hasParam("kring")) {
      kringString = request->getParam("kring")->value();
      kringnr = kringString.toInt();
      Print("kring = ");
      Println(kringnr);
    }
    else {
      kringnr = 0;
    }
    if (request->hasParam("veld")) {
      veldString = request->getParam("veld")->value();
      veldnr = veldString.toInt();
      Print("veldnr = ");
      Println(veldnr);

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

        /* lijstje
 1  char   desc;
 2  int    startled;
 3  int    stopled;
 4  int    hue1;
 5  int    sat1;
 6  int    bright1;
 7  int    hue2;
 8  int    sat2;
 9  int    bright2;
10  int    hue3;
11  int    sat3;
12  int    bright3;
13  int    hue4;
14  int    sat4;
15  int    bright4;
16  int    every;*/
      default:
        answertoSend = "error";
        break;
      }
      Print("result dat zal worden doorgestuurd = ");
      Println(answertoSend);

    }
    else {
      answertoSend = "error";
    }
    request->send(200, "text/plain", answertoSend);
  });
  
  webserver.on(hdlCSS, HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/style.css", "text/plain");
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