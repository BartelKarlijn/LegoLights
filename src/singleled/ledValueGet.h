String ledValueGet(){
    int lednr = ledRequest.lednr;
    int veldnr = ledRequest.veld;
    String answertoSend = "";
    // get parameter led & veld  http://192.168.68.205/maintain_strip?led=1?veld=hue1
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
      case 56:
        answertoSend = ledsingle[lednr].image;
        break;
      case 57:
        answertoSend = ledsingle[lednr].animatie;
        break;
      default:
        answertoSend = "error";
        break;
      }
    return answertoSend;
}