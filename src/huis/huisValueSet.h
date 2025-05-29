String huisValueSet(){
    int lednr = huisRequest.lednr;
    int rgbnr = huisRequest.rgbnr;
    int veldnr = huisRequest.veld;
    String waardeString = huisRequest.waarde;
    String answertoSend;
    // get parameter led & veld & waarde http://192.168.68.205/maintain_strip?led=1&veld=hue1&waarde=56
    
    Println("Huis,  veld: " + String(veldnr) + " led: " + lednr + " waarde: " + waardeString);
    // verwerk de input
      switch (veldnr)
      {
      case 40:  //we beginnen bij 50, zodat 0 een fout geeft (strip is 1-50)
        huisSetting.desc     = waardeString;
        answertoSend = waardeString;
        break;
      case 41:
        huisSetting.image = waardeString;
        answertoSend = waardeString;
        break;
      case 42:
        huisSetting.huisnr = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 43:
        huisSetting.animnrled[lednr] = waardeString.toInt();
        answertoSend = waardeString;
        break;
      case 44:
        huisSetting.animnrrgb[rgbnr] = waardeString.toInt();
        answertoSend = waardeString;
        break;
      default:
        answertoSend = "error";
        break;
      }
    return answertoSend;
}