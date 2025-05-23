String huisValueGet(){
    int lednr = huisRequest.lednr;
    int veldnr = huisRequest.veld;
    
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
      case 43:
        answertoSend = huisSetting.animnr[lednr];
        break;
      default:
        answertoSend = "error";
        break;
      }
    return answertoSend;
}