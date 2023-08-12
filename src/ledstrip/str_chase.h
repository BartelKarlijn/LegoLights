#pragma once

void str_chase(int kring) {
  unsigned long timeBezig;
  bool flag_on;

  timeBezig = currentMillis - timer_str_aan[kring];
  // bereken mode (uit, up, down)
  if( timeBezig > (str_time1[kring] + str_time2[kring]) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_str_aan[kring] = currentMillis;      //reset timers
    timer_str_flicker[kring] = currentMillis + str_tim_flick[kring];
    chasestrnr[kring] = str_startled[kring];
    flag_on = true;
  }
  else  if (timeBezig > str_time1[kring]) { // einde van aan
    flag_on = false;
  }
  else  if(currentMillis >  timer_str_flicker[kring]) {        //naar volgend spotje gaan
    flag_on = true;
    timer_str_flicker[kring] = currentMillis + str_tim_flick[kring] ; //reset flikkertimer
    chasestrnr[kring]++;
    if (chasestrnr[kring] > str_stopled[kring]) {
      chasestrnr[kring] = str_startled[kring];
    }
  }
  else {
    // gewoon verder doen, laat lampje maar branden
    flag_on = true;
  }

  for (size_t i = str_startled[kring]; i <= str_stopled[kring]; i++)  {
    // aan of uit zetten?
    if (flag_on) {
      if( i == chasestrnr[kring] ) {
        ledstrip[i] = CHSV(str_hue1[kring], str_sat1[kring], str_bright1[kring]);
      }
      else {
        ledstrip[i] = CHSV(str_hue2[kring], str_sat2[kring], str_bright2[kring]);
      }
    }
    else {
      ledstrip[i] = CRGB::Black;
    }
  }
}
