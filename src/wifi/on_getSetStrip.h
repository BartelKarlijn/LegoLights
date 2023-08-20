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
        waardeString.toCharArray(kring[kringnr].desc, 20);
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
        kring[kringnr].bright1 = waardeString.toInt();
        answertoSend = waardeString;
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
    return answertoSend;
}