void setup_AsyncWebserver(){
  // Voordat we de webserver starten, moet je OTA opstarten, hier zonder user/pw
  AsyncElegantOTA.begin(&webserver);

  // Analoog gaan we de WebSerial opstarten, zodat je kan zien wat er gebeurt
  WebSerial.begin(&webserver);

  // if url isn't found
  webserver.onNotFound([](AsyncWebServerRequest *request) {
    Println("Wifi page not found");
    request->send(404, "text/plain", "Not found");
  });

  // Route for root / web page (controller)
  webserver.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Root requested");
    //request->send(SPIFFS, "/index.html", String(), false, html_processorRoot);
    request->send(SPIFFS, "/index.html", "text/html");
  });
  webserver.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/favicon.ico", "image/png");
  });
  webserver.on("/file", HTTP_GET, [](AsyncWebServerRequest * request){
    Println("file requested");
    on_file(request);
  });
  webserver.on("/fileList", HTTP_GET, [](AsyncWebServerRequest * request){
    Println("fileList requested");
    request->send(200, "text/plain", listFiles(true));
  });
  webserver.on("/fileManagement", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("FileManagement requested");
    request->send(SPIFFS, "/fileManagement.html", "text/html");
  });
  webserver.on("/jquery-3.7.0.min.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/jquery-3.7.0.min.js", "text/javascript");
  });
  webserver.on("/maintain_strip", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("strip configuratie opgeroepen");
    request->send(SPIFFS, "/maintain_strip.html", "text/html");
  });
  webserver.on("/getStrip", HTTP_GET, [](AsyncWebServerRequest *request) {
    //Println("getstrip binnen gekregen"); geen print want we krijgen er zo 10 binnen
    request->send(200, "text/plain", on_getstrip(request));
  });
  webserver.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/style.css", "text/plain");
  });
  webserver.on("/wificfg", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Wifi config pagina");
    request->send(SPIFFS, "/index.html", String(), false, html_processorWifi);
  });
  webserver.on("/wifisave", HTTP_GET, [](AsyncWebServerRequest *request) {
    Println("Wifi connection parameters");
    on_wifisave(request);
    request->send(SPIFFS, "/index.html", String(), false, html_processorWifi);
  });

  // Start server
  webserver.begin();
}