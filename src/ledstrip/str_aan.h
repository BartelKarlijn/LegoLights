#pragma once

void str_aan(int kring) {
  bool fl_on;
  unsigned long timeBezig;

  timeBezig = currentMillis - timer_str_aan[kring];

  if( timeBezig > (str_time1[kring] + str_time2[kring]) ) {   // lang genoeg uit geweest.  Nu aanzetten
    fl_on = true;
    timer_str_aan[kring] = currentMillis; //reset timer
  }
  else  if (timeBezig > str_time1[kring]) { // lang genoeg aan geweest
    fl_on = false;
  }
  else {     //laat nog maar tijdje aan.
    fl_on = true;
  }

  for (size_t i = str_startled[kring]; i <= str_stopled[kring]; i++)
  {
    // aan of uit zetten?
    if (fl_on) {
      if( ( (i - str_startled[kring]) % str_every[kring] ) == 0 ) {  // check every
        ledstrip[i] = CHSV(str_hue1[kring], 255, str_bright1[kring] );
      }
      else {
        ledstrip[i] = CRGB::Black;
      }
    }
    else {
      ledstrip[i] = CRGB::Black;
    }
  }
}
