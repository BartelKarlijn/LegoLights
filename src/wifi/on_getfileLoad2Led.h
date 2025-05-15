String on_getfileLoad2Led(AsyncWebServerRequest *request){
    String ledString;
    int lednr;
    // get parameter led & veld  http://192.168.68.205/getfileLoad2Led?led=1
    if (request->hasParam("led")) {
      ledString = request->getParam("led")->value();
      lednr = ledString.toInt();
    }
    else {
      lednr = 99;
    }
    return fileLoadLed(lednr, ledsingle[lednr].animatie);
  }
  
