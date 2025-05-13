String on_getLed(AsyncWebServerRequest *request){
    String ledString;
    int lednr;
    String veldString;
    int veldnr;
    String answertoSend;
    // get parameter led & veld  http://192.168.68.205/maintain_strip?led=1?veld=hue1
    if (request->hasParam("led")) {
      ledString = request->getParam("led")->value();
      lednr = ledString.toInt();
    }
    else {
      lednr = 99;
    }
    if (request->hasParam("veld")) {
      veldString = request->getParam("veld")->value();
      veldnr = veldString.toInt();

      switch (veldnr)
      {
        case 50:  //we beginnen bij 1, zodat 0 een fout geeft
        answertoSend = ledsingle[lednr].desc;
        break;
      case 51:
        answertoSend = ledsingle[lednr].bri;
        break;
      case 52:
        answertoSend = ledsingle[lednr].effect;
        break;
      case 53:
        answertoSend = ledsingle[lednr].timeon;
        break;
      case 54:
        answertoSend = ledsingle[lednr].timeoff;
        break;
      case 55:
        answertoSend = ledsingle[lednr].timeeffect;
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