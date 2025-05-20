String on_getsettingLedApplyAnim(AsyncWebServerRequest *request){
    String ledString;
    int lednr;
    int animnr;
    if (request->hasParam("led")) {
      ledString = request->getParam("led")->value();
      lednr = ledString.toInt();
    }
    else {
      lednr = 99;
    }
    if (request->hasParam("anim")) {
      ledString = request->getParam("anim")->value();
      animnr = ledString.toInt();
    }
    else {
      animnr = 0;
    }
    settingLedApplyAnim(lednr, animnr);
    return "Animatie "+String(animnr)+" op led "+String(lednr)+" toegepast";
  }
 
