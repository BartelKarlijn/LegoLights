String huisValueGet(){
  size_t animnr = huisRequest.animnr; 
  size_t veldnr = huisRequest.veld;
    
    String answertoSend = "";
    switch (veldnr)
    {
      case 40:  //we beginnen bij 1, zodat 0 een fout geeft
          answertoSend = huisSetting.desc;
        break;
      case 41:
          answertoSend = huisSetting.image;
        break;
      case 42:
        answertoSend = huisSetting.huisnr;
        break;
      case 45:
        answertoSend = huisSetting.animnrhuis;
        break;
      case 46:
        answertoSend = huisSetting.animdesc[animnr];
        break;
      case 47:
        answertoSend = huisSetting.animdefault;
        break;
      case 48:
        answertoSend = huisSetting.newMACadress;
        break;
      default:
        answertoSend = "error";
        break;
      }
    return answertoSend;
}