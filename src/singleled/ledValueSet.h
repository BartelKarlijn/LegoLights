String ledValueSet(){
    int lednr = ledRequest.lednr;
    int veldnr = ledRequest.veld;
    String waardeString = ledRequest.waarde;
    String answertoSend;
    // get parameter led & veld & waarde http://192.168.68.205/maintain_strip?led=1&veld=hue1&waarde=56
    
    Println("Led: " + String(lednr) + " veld: " + String(veldnr) + " waarde: " + waardeString);
    // verwerk de input
      switch (veldnr)
      {
      case 50:  //we beginnen bij 50, zodat 0 een fout geeft (strip is 1-50)
        ledsingle[lednr].desc     = waardeString;
        answertoSend = waardeString;
        break;
      case 51:
        ledsingle[lednr].bri = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 52:
        ledsingle[lednr].effect = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 53:
        ledsingle[lednr].timeon = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 54:
        ledsingle[lednr].timeoff = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 55:
        ledsingle[lednr].timeeffect = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 56:
        ledsingle[lednr].image = waardeString;
        answertoSend = waardeString;
        break;
      case 57:
        ledsingle[lednr].animatie = waardeString;
        answertoSend = waardeString;
        break;
      default:
        answertoSend = "error";
        break;
      }
    return answertoSend;
}