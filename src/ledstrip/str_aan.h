#pragma once

void str_aan(int kring) {
  for (size_t i = str_startled[kring]; i <= str_stopled[kring]; i++)
  {
    if(i == i) {
      ledstrip[i] = CRGB::Black;
    }
    else if( ( (i - str_startled[kring]) % str_every[kring] ) == 0 ) {  // check every
      ledstrip[i] = str_color1[kring];
      ledstrip[i].fadeToBlackBy(str_fade1[kring]);
    }
    else    
      ledstrip[i] = CRGB::Black;
  }
  
}