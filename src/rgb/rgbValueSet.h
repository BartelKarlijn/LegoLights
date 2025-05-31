String rgbValueSet(){
    size_t rgbnr = rgbRequest.rgbnr;
    size_t animnr = rgbRequest.animnr;
    size_t veldnr = rgbRequest.veld;
    String waardeString = rgbRequest.waarde;
    String answertoSend;
    
    Println("Rgb: " + String(rgbnr) + " veld: " + String(veldnr) + " waarde: " + waardeString);
    // verwerk de input
      switch (veldnr)
      {
      case  1:  //we beginnen bij 50, zodat 0 een fout geeft (strip is 1-50)
        rgbactive[rgbnr].desc     = waardeString;
        rgbsettings[rgbnr].rgbdesc = waardeString;
        answertoSend = waardeString;
        break;
      case  2:
        rgbactive[rgbnr].startrgb = waardeString.toInt();
        rgbsettings[rgbnr].startrgb = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case  3:
        rgbactive[rgbnr].stoprgb = waardeString.toInt();
        rgbsettings[rgbnr].stoprgb = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case  4:
        rgbactive[rgbnr].hue1 = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].hue1 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case  5:
        rgbactive[rgbnr].sat1 = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].sat1 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case  6:
        rgbactive[rgbnr].bri1 = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].bri1 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case  7:
        rgbactive[rgbnr].hue2 = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].hue2 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case  8:
        rgbactive[rgbnr].sat2 = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].sat2 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case  9:
        rgbactive[rgbnr].bri2 = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].bri2 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 10:
        rgbactive[rgbnr].hue3 = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].hue3 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 11:
        rgbactive[rgbnr].sat3 = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].sat3 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 12:
        rgbactive[rgbnr].bri3 = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].bri3 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 13:
        rgbactive[rgbnr].hue4 = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].hue4 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 14:
        rgbactive[rgbnr].sat4 = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].sat4 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 15:
        rgbactive[rgbnr].bri4 = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].bri4 = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 16:
        rgbactive[rgbnr].every = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].every = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 17:
        rgbactive[rgbnr].timeon = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].timeon = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 18:
        rgbactive[rgbnr].timeoff = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].timeoff = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 19:
        rgbactive[rgbnr].timeeffect = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].timeeffect = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 20:
        rgbactive[rgbnr].seed = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].seed = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 21:
        rgbactive[rgbnr].effect = waardeString.toInt();
        rgbsettings[rgbnr].anim[animnr].effect = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 22:
        rgbactive[rgbnr].animnr = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 23:
        rgbactive[rgbnr].animatie = waardeString;
        rgbsettings[rgbnr].anim[animnr].animdesc = waardeString;
        answertoSend = waardeString;
        break;
      case 24:
        rgbactive[rgbnr].image = waardeString;
        rgbsettings[rgbnr].rgbimage = waardeString;
        answertoSend = waardeString;
        break;
      default:
        answertoSend = "error";
        break;
      }
    return answertoSend;
}