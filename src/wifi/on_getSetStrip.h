String on_getSetStrip(AsyncWebServerRequest *request){
    String kringString;
    int kringnr;
    String veldString;
    int veldnr;
    String answertoSend;
    String waardeString;
    bool doeVerder;
    // get parameter kring & veld & waarde http://192.168.68.205/maintain_strip?kring=1&veld=hue1&waarde=56
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
      doeVerder = true;
    }
    else {
      answertoSend += "Error: veld mist";
    }
    if (request->hasParam("waarde")) {
      waardeString = request->getParam("waarde")->value();
      doeVerder = true;
    }
    else {
      answertoSend += "Error: waardeparameter mist";
    }

    // verwerk de input
    if (doeVerder) {
      switch (veldnr)
      {
      case 1:  //we beginnen bij 1, zodat 0 een fout geeft
        kring[kringnr].desc     = waardeString;
        answertoSend = waardeString;
        break;
      case 2:
        kring[kringnr].startled = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 3:
        kring[kringnr].stopled = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 4:
        kring[kringnr].hue1 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 5:
        kring[kringnr].sat1 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 6:
        kring[kringnr].bri1 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 7:
        kring[kringnr].hue2 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 8:
        kring[kringnr].sat2 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 9:
        kring[kringnr].bri2 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 10:
        kring[kringnr].hue3 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 11:
        kring[kringnr].sat3 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 12:
        kring[kringnr].bri3 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 13:
        kring[kringnr].hue4 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 14:
        kring[kringnr].sat4 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 15:
        kring[kringnr].bri4 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 16:
        kring[kringnr].every = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 17:
        kring[kringnr].timeon = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 18:
        kring[kringnr].timeoff = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 19:
        kring[kringnr].timeeffect = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 20:
        kring[kringnr].seed = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 21:
        kring[kringnr].effect = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 22:
        kring[kringnr].image = waardeString;
        answertoSend = waardeString;
        break;
      default:
        answertoSend = "error";
        break;
      }
    }
    return answertoSend;
}