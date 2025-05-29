String rgbValueGet(){
    int lednr = ledRequest.lednr;
    int veldnr = ledRequest.veld;
    String answertoSend = "";
    // get parameter led & veld  http://192.168.68.205/maintain_strip?led=1?veld=hue1
      switch (veldnr)
      {
        case 50:  //we beginnen bij 1, zodat 0 een fout geeft
          answertoSend = ledactive[lednr].desc;
        break;
      case 51:
          answertoSend = ledactive[lednr].bri;
        break;
      case 52:
        answertoSend = ledactive[lednr].effect;
        break;
      case 53:
        answertoSend = ledactive[lednr].timeon;
        break;
      case 54:
        answertoSend = ledactive[lednr].timeoff;
        break;
      case 55:
        answertoSend = ledactive[lednr].timeeffect;
        break;
      case 56:
        answertoSend = ledactive[lednr].image;
        break;
      case 57:
        answertoSend = ledactive[lednr].animatie;
        break;
      default:
        answertoSend = "error";
        break;
      }
    return answertoSend;
}