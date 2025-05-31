#pragma once

void rgb_aan(size_t kringnr) {
  bool fl_on;
  unsigned long timeBezig;

  timeBezig = currentMillis - timer_rgb_aan[kringnr];

  if( timeBezig > (kring[kringnr].timeon + kring[kringnr].timeoff) ) {   // lang genoeg uit geweest.  Nu aanzetten
    fl_on = true;
    timer_rgb_aan[kringnr] = currentMillis; //reset timer
  }
  else  if (timeBezig > kring[kringnr].timeon) { // lang genoeg aan geweest
    fl_on = false;
  }
  else {     //laat nog maar tijdje aan.
    fl_on = true;
  }

  for (size_t i = kring[kringnr].startrgb; i <= kring[kringnr].stoprgb; i++)
  {
    // aan of uit zetten?
    if (fl_on) {
      if( ( (i - kring[kringnr].startrgb + kring[kringnr].seed + 30*kring[kringnr].every) % kring[kringnr].every ) == 0 ) {  // check every.  Aangezien negatieve waarden kunnen voorkomen, tellen we er 30 x every bij op om zeker positieve waarden te hebben
        rgbstrip[i] = CHSV(kring[kringnr].hue1, kring[kringnr].sat1, kring[kringnr].bri1 );
      }
      else {
        rgbstrip[i] = CHSV(kring[kringnr].hue2, kring[kringnr].sat2, kring[kringnr].bri2 );
      }
    }
    else {
      rgbstrip[i] = CRGB::Black;
    }
  }
}
