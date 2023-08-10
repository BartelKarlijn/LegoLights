#pragma once

void str_glow(int kring) {
  for (size_t i = str_startled[kring]; i <= str_stopled[kring]; i++)
  {
    if ( ( (i - str_startled[kring]) % str_every[kring] ) == 0 ) {
      ledstrip[i] = str_color1[kring];
      ledstrip[i].fadeToBlackBy(str_fade1[kring]);
    }
    else    
      ledstrip[i] = CRGB::Black;
  }
  
}