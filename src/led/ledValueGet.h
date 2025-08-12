String ledValueGet(){
    size_t lednr = ledRequest.lednr;
    size_t animnr = huisSetting.animnrhuis;
    size_t veldnr = ledRequest.veld;
    String answertoSend = "";
    // get parameter led & veld  http://192.168.68.205/maintain_strip?led=1?veld=hue1
      switch (veldnr)
      {
      case 50:  //we beginnen bij 1, zodat 0 een fout geeft
        answertoSend            = ledsettings[lednr].leddesc;
        ledactive[lednr].desc   = ledsettings[lednr].leddesc;
        break;
      case 51:
        answertoSend            = ledsettings[lednr].anim[animnr].bri;
        ledactive[lednr].bri    = ledsettings[lednr].anim[animnr].bri;
        break;
      case 52:
        answertoSend            = ledsettings[lednr].anim[animnr].effect;
        ledactive[lednr].effect = ledsettings[lednr].anim[animnr].effect;
        break;
      case 53:
        answertoSend            = ledsettings[lednr].anim[animnr].timeon;
        ledactive[lednr].timeon = ledsettings[lednr].anim[animnr].timeon;
        break;
      case 54:
        answertoSend            = ledsettings[lednr].anim[animnr].timeoff;
        ledactive[lednr].timeoff = ledsettings[lednr].anim[animnr].timeoff;
        break;
      case 55:
        answertoSend            = ledsettings[lednr].anim[animnr].timeeffect;
        ledactive[lednr].timeeffect = ledsettings[lednr].anim[animnr].timeeffect;
        break;
      case 56:
        answertoSend            = ledsettings[lednr].ledimage;
        ledactive[lednr].image  = ledsettings[lednr].ledimage;
        break;
      default:
        answertoSend = "error";
        break;
      }
    return answertoSend;
}