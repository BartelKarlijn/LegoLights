String ledValueSet(){
    uint8_t lednr = ledRequest.lednr;
    uint8_t animnr = ledRequest.animnr;
    uint8_t veldnr = ledRequest.veld;
    String waardeString = ledRequest.waarde;
    String answertoSend;
    // get parameter led & veld & waarde http://192.168.68.205/maintain_strip?led=1&veld=hue1&waarde=56
    
    Println("Led: " + String(lednr) + " veld: " + String(veldnr) + " waarde: " + waardeString);
    // verwerk de input
      switch (veldnr)
      {
      case 50:  //we beginnen bij 50, zodat 0 een fout geeft (strip is 1-50)
        ledactive[lednr].desc      = waardeString;
        ledsettings[lednr].leddesc = waardeString;
        answertoSend = waardeString;
        break;
      case 51:
        ledactive[lednr].bri = waardeString.toInt();
        ledsettings[lednr].anim[animnr].bri = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 52:
        ledactive[lednr].effect = waardeString.toInt();
        ledsettings[lednr].anim[animnr].effect = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 53:
        ledactive[lednr].timeon = waardeString.toInt();
        ledsettings[lednr].anim[animnr].timeon = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 54:
        ledactive[lednr].timeoff = waardeString.toInt();
        ledsettings[lednr].anim[animnr].timeoff = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 55:
        ledactive[lednr].timeeffect = waardeString.toInt();
        ledsettings[lednr].anim[animnr].timeeffect = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 56:
        ledactive[lednr].image = waardeString;
        ledsettings[lednr].ledimage = waardeString;
        answertoSend = waardeString;
        break;
      default:
        answertoSend = "error";
        break;
      }
    return answertoSend;
}