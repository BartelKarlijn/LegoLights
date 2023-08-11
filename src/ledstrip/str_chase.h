#pragma once

void str_chase(int kring) {
  unsigned long timeBezig;

  timeBezig = currentMillis - timer_str_aan[kring];
  // bereken mode (uit, up, down)
  if( timeBezig > (str_time1[kring] + str_time2[kring]) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_str_aan[kring] = currentMillis;      //reset timers
    timer_str_flicker[kring] = currentMillis + str_time_flick[kring];
    chasestrnr[kring] = str_startled[kring];
  }
  else  if (timeBezig > str_time1[kring]) { // einde van aan
    flamestrbright[kring] = 0;
    ledstrip[chasestrnr[kring]] = CRGB::Black;
  }
  else  if(currentMillis >  timer_str_flicker[kring]) {        //naar volgend spotje gaan
    //flamestrhueidx[kring] = (flamestrhueidx[kring] + 1) % 4; //we hebben 4 kleuren, doe er eentje bij
    timer_str_flicker[kring] = currentMillis + str_time_flick[kring] ; //reset flikkertimer
    chasestrnr[kring]++;
    if (chasestrnr[kring] > str_stopled[kring]) {
      chasestrnr[kring] = str_startled[kring];
    }
  }
  else {
    // gewoon verder doen, laat lampje maar branden
  }

// bereken kleur
  //  switch (flamestrhueidx[kring])
  //  {
  //  case 0:
  //   flamestrhue[kring] = str_hue1[kring];
  //   break;
  //  case 1:
  //   flamestrhue[kring] = str_hue2[kring];
  //   break;
  //  case 2:
  //   flamestrhue[kring] = str_hue3[kring];
  //   break;
  //  case 3:
  //   flamestrhue[kring] = str_hue4[kring];
  //   break;
  //  default:
  //   flamestrhue[kring] = 0;
  //   break;
  //  }

  for (size_t i = str_startled[kring]; i <= str_stopled[kring]; i++)  {
    // aan of uit zetten?
    if( i == chasestrnr[kring] ) {
      ledstrip[i] = CHSV(str_hue1[kring], 255, str_bright1[kring]);
    }
    else {
      ledstrip[i] = CRGB::Black;
    }
  }
}
