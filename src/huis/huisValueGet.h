String huisValueGet(){
    size_t lednr = huisRequest.lednr;
    size_t rgbnr = huisRequest.rgbnr;
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
      case 43:
        answertoSend = huisSetting.animnrled[lednr];
        break;
      case 44:
        answertoSend = huisSetting.animnrrgb[rgbnr];
        break;
      default:
        answertoSend = "error";
        break;
      }
    return answertoSend;
}