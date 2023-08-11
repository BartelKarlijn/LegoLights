#pragma once

void str_glow(int kring) {
  unsigned long timeBezig;
  unsigned long timeMap;
  int brightn_glow;

timeBezig = currentMillis - timer_str_aan[kring];
// bereken mode (uit, up, down)
  if( timeBezig > (2 * str_time1[kring] + str_time2[kring]) ) {   // up+down+uit = lang genoeg uit geweest.  Nu aanzetten
    Print("cycles ");
    Print(String(cnt));
    Print(" - Timemap ");
    Print(String(timeMap));
    Print(" - Brightness ");
    Println(String(brightPrint));
    cnt = 0;
    firstpassed = false;
    brightn_glow = 0;
    timer_str_aan[kring] = currentMillis; //reset timer
  }
  else  if (timeBezig > 2 * str_time1[kring]) { // einde van glow down
    brightn_glow = 0;
  }
  else  if (timeBezig > str_time1[kring]) { // down aan het gaan
    timeMap = timeBezig - str_time1[kring];
    brightn_glow = map(timeMap, 0, str_time1[kring], str_bright1[kring], 0);
    cnt = cnt + 1;
    if (not firstpassed) {
      brightPrint = brightn_glow;
      TimeMapPrint = timeMap;
      firstpassed = true;
    }
  }
  else {     //nog tijdje up te gaan.
    brightn_glow = map(timeBezig, 0, str_time1[kring], 0, str_bright1[kring] );
  }

  for (size_t i = str_startled[kring]; i <= str_stopled[kring]; i++)
  {
    // aan of uit zetten?
    if( ( (i - str_startled[kring]) % str_every[kring] ) == 0 ) {  // check every
      ledstrip[i] = CHSV(str_hue1[kring], 255, brightn_glow );
    }
    else {
      ledstrip[i] = CRGB::Black;
    }
  }
}
