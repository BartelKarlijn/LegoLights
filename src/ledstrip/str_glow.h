#pragma once

void str_glow(int kringnr) {
  unsigned long timeBezig;
  unsigned long timeMap;
  uint8_t brightn_glow;

timeBezig = currentMillis - timer_str_aan[kringnr];
// bereken mode (uit, up, down)
  if( timeBezig > (2 * kring[kringnr].timeon + kring[kringnr].timeoff) ) {   // up+down+uit = lang genoeg uit geweest.  Nu aanzetten
    brightn_glow = 0;
    timer_str_aan[kringnr] = currentMillis; //reset timer
  }
  else  if (timeBezig > 2 * kring[kringnr].timeon) { // einde van glow down
    brightn_glow = 0;
  }
  else  if (timeBezig > kring[kringnr].timeon) { // down aan het gaan
    timeMap = timeBezig - kring[kringnr].timeon;
    brightn_glow = map(timeMap, 0, kring[kringnr].timeon, kring[kringnr].bright1, 0);
  }
  else {     //nog tijdje up te gaan.
    brightn_glow = map(timeBezig, 0, kring[kringnr].timeon, 0, kring[kringnr].bright1 );
  }

  for (int i = kring[kringnr].startled; i <= kring[kringnr].stopled; i++)
  {
    // aan of uit zetten?
    if( ( (i - kring[kringnr].startled) % kring[kringnr].every ) == 0 ) {  // check every
      ledstrip[i] = CHSV(kring[kringnr].hue1, 255, brightn_glow );
    }
    else {
      ledstrip[i] = CRGB::Black;
    }
  }
}
