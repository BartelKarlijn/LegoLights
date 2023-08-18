void on_file(AsyncWebServerRequest *request) {
  Println("File requested");
  String logmessage;
  if (request->hasParam("name") && request->hasParam("action")) {
    const char *fileName = request->getParam("name")->value().c_str();
    const char *fileAction = request->getParam("action")->value().c_str();

    logmessage = "Requested file ?name=" + String(fileName) + "&action=" + String(fileAction);

    if (!SPIFFS.exists(fileName)) {
      Println(logmessage + " ERROR: file does not exist");
      Print("file='");
      Print(fileName);
      Print("'");
      Print("spiffs output geeft ");
      Println(SPIFFS.exists(fileName));
      request->send(400, "text/plain", "ERROR: file does not exist");
    } else {
      Println(logmessage + " file exists");
      if (strcmp(fileAction, "download") == 0) {
        logmessage += " downloaded";
        request->send(SPIFFS, fileName, "application/octet-stream");
      } else if (strcmp(fileAction, "delete") == 0) {
        logmessage += " deleted";
        SPIFFS.remove(fileName);
        request->send(200, "text/plain", "Deleted File: " + String(fileName));
      } else {
        logmessage += " ERROR: invalid action param supplied";
        request->send(400, "text/plain", "ERROR: invalid action param supplied");
      }
      Println(logmessage);
  }
  } else {
    request->send(400, "text/plain", "ERROR: name and action params required");
  }
}
