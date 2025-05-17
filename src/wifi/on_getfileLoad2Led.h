String on_getfileLoad2Led(AsyncWebServerRequest *request){
    String ledString;
    String anim;
    int lednr;
    // get parameter led & veld  http://192.168.68.205/getfileLoad2Led?led=1
    if (request->hasParam("led")) {
      ledString = request->getParam("led")->value();
      lednr = ledString.toInt();
    }
    else {
      lednr = 99;
    }
    if (request->hasParam("animati")) {
      anim = request->getParam("animati")->value();
    }
    else {
      anim = "default";
    }
    return fileLoadLed(lednr, anim);
  }
  
