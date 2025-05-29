String rgbValueGet(){
    int rgbnr = rgbRequest.rgbnr;
    int veldnr = rgbRequest.veld;
    String answertoSend = "";
    switch (veldnr)
      {
      case  1:  //we beginnen bij 1, zodat 0 een fout geeft
          answertoSend = rgbactive[rgbnr].desc;
        break;
      case  2:
          answertoSend = rgbactive[rgbnr].startrgb;
        break;
      case  3:
          answertoSend = rgbactive[rgbnr].stoprgb;
        break;
      case  4:
        answertoSend = rgbactive[rgbnr].hue1;
        break;
      case  5:
        answertoSend = rgbactive[rgbnr].sat1;
        break;
      case  6:
        answertoSend = rgbactive[rgbnr].bri1;
        break;
      case  7:
        answertoSend = rgbactive[rgbnr].hue2;
        break;
      case  8:
        answertoSend = rgbactive[rgbnr].sat2;
        break;
      case  9:
        answertoSend = rgbactive[rgbnr].bri2;
        break;
      case 10:
        answertoSend = rgbactive[rgbnr].hue3;
        break;
      case 11:
        answertoSend = rgbactive[rgbnr].sat3;
        break;
      case 12:
        answertoSend = rgbactive[rgbnr].bri3;
        break;
      case 13:
        answertoSend = rgbactive[rgbnr].hue4;
        break;
      case 14:
        answertoSend = rgbactive[rgbnr].sat4;
        break;
      case 15:
        answertoSend = rgbactive[rgbnr].bri4;
        break;
      case 16:
        answertoSend = rgbactive[rgbnr].every;
        break;
      case 17:
        answertoSend = rgbactive[rgbnr].timeon;
        break;
      case 18:
        answertoSend = rgbactive[rgbnr].timeoff;
        break;
      case 19:
        answertoSend = rgbactive[rgbnr].timeeffect;
        break;
      case 20:
        answertoSend = rgbactive[rgbnr].seed;
        break;
      case 21:
        answertoSend = rgbactive[rgbnr].effect;
        break;
      case 22:
        answertoSend = rgbactive[rgbnr].animnr;
        break;
      case 23:
        answertoSend = rgbactive[rgbnr].animatie;
        break;
      default:
        answertoSend = "error";
        break;
      }
    return answertoSend;
}