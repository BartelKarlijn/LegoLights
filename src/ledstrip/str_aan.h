#pragma once

void str_aan(int kringnr) {
  bool fl_on;
  unsigned long timeBezig;

  timeBezig = currentMillis - timer_str_aan[kringnr];

  if( timeBezig > (kring[kringnr].timeon + kring[kringnr].timeoff) ) {   // lang genoeg uit geweest.  Nu aanzetten
    fl_on = true;
    timer_str_aan[kringnr] = currentMillis; //reset timer
  }
  else  if (timeBezig > kring[kringnr].timeon) { // lang genoeg aan geweest
    fl_on = false;
  }
  else {     //laat nog maar tijdje aan.
    fl_on = true;
  }

  for (int i = kring[kringnr].startled; i <= kring[kringnr].stopled; i++)
  {
    // aan of uit zetten?
    if (fl_on) {
      if( ( (i - kring[kringnr].startled) % kring[kringnr].every ) == 0 ) {  // check every
        ledstrip[i] = CHSV(kring[kringnr].hue1, kring[kringnr].sat1, kring[kringnr].bright1 );
      }
      else {
        ledstrip[i] = CHSV(kring[kringnr].hue2, kring[kringnr].sat2, kring[kringnr].bright2 );
      }
    }
    else {
      ledstrip[i] = CRGB::Black;
    }
  }
}
