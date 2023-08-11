#pragma once

void str_chase(int kring) {
  unsigned long timeBezig;

  timeBezig = currentMillis - timer_str_aan[kring];
  // bereken mode (uit, up, down)
  if( timeBezig > (str_time1[kring] + str_time2[kring]) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_str_aan[kring] = currentMillis;      //reset timers
    timer_str_flicker[kring] = currentMillis + str_time_flick[kring];
    flamestrhueidx[kring] = 0;
    flamestrbright[kring] = str_bright1[kring];
    str_startled[kring] = 0;
  }
  else  if (timeBezig > str_time1[kring]) { // einde van aan
    flamestrbright[kring] = 0;
  }
  else  if(currentMillis >  timer_str_flicker[kring])  {//naar volgend spotje gaan
    //flamestrhueidx[kring] = (flamestrhueidx[kring] + 1) % 4; //we hebben 4 kleuren, doe er eentje bij
    flamestrhueidx[kring] = 0;
    flamestrbright[kring] = str_bright1[kring];
    timer_str_flicker[kring] = currentMillis + str_time_flick[kring] ; //reset flikkertimer
    str_startled[kring] = (str_startled[kring] + 1 ) % (str_stopled[kring] - str_startled[kring] + 1)
  }
  else {
    // gewoon verder doen, laat lampje maar branden
  }

// bereken kleur
   switch (flamestrhueidx[kring])
   {
   case 0:
    flamestrhue[kring] = str_hue1[kring];
    break;
   case 1:
    flamestrhue[kring] = str_hue2[kring];
    break;
   case 2:
    flamestrhue[kring] = str_hue3[kring];
    break;
   case 3:
    flamestrhue[kring] = str_hue4[kring];
    break;
   default:
    flamestrhue[kring] = 0;
    break;
   }

  for (size_t i = str_startled[kring]; i <= str_stopled[kring]; i++)  {
    // aan of uit zetten?
    if( i == chasestrnr[kring] ) {  // check every
      ledstrip[i] = CHSV(flamestrhue[kring], 255, flamestrbright[kring]);
    }
    else {
      ledstrip[i] = CRGB::Black;
    }
  }
}
