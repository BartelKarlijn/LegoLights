String on_getStrip(AsyncWebServerRequest *request){
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
      kringnr = 99;
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
        answertoSend = kring[kringnr].bri1;
        break;
      case 7:
        answertoSend = kring[kringnr].hue2;
        break;
      case 8:
        answertoSend = kring[kringnr].sat2;
        break;
      case 9:
        answertoSend = kring[kringnr].bri2;
        break;
      case 10:
        answertoSend = kring[kringnr].hue3;
        break;
      case 11:
        answertoSend = kring[kringnr].sat3;
        break;
      case 12:
        answertoSend = kring[kringnr].bri3;
        break;
      case 13:
        answertoSend = kring[kringnr].hue4;
        break;
      case 14:
        answertoSend = kring[kringnr].sat4;
        break;
      case 15:
        answertoSend = kring[kringnr].bri4;
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
        answertoSend = kring[kringnr].seed;
        break;
      case 21:
        answertoSend = kring[kringnr].effect;
        break;
      case 22:
        answertoSend = kring[kringnr].image;
        break;
      default:
        answertoSend = "error";
        break;
      }
    }
    else {
      answertoSend = "error";
    }
    return answertoSend;
}