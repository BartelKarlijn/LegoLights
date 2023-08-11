#pragma once

void str_glow(int kring) {
  bool fl_on;
  bool fl_up;
  unsigned long timeBezig;
  int  glowfade;

timeBezig = currentMillis - timer_str_aan[kring];
// bereken mode (uit, up, down)
  if( timeBezig > (2 * str_time1[kring] + str_time2[kring]) ) {   // up+down+uit = lang genoeg uit geweest.  Nu aanzetten
    fl_on = true;
    fl_up = true;
    timer_str_aan[kring] = currentMillis; //reset timer
  }
  else  if (timeBezig > 2 * str_time1[kring]) { // einde van glow down
    fl_on = false;
  }
  else  if (timeBezig > str_time1[kring]) { // einde van glow up
    fl_on = true;
    fl_up = false;
  }
  else {     //nog tijdje up te gaan.
    fl_on = true;
    fl_up = true;
  }

// bereken level
  if( fl_on and fl_up ){
    glowfade = map(timeBezig, 0, str_time1[kring], 0, 255 );
  }
  else {
    glowfade = map(timeBezig, 0, str_time1[kring], 255, 0 );
  }

  for (size_t i = str_startled[kring]; i <= str_stopled[kring]; i++)
  {
    // aan of uit zetten?
    if (fl_on) {
      if( ( (i - str_startled[kring]) % str_every[kring] ) == 0 ) {  // check every
        ledstrip[i] = str_color1[kring];
        ledstrip[i].fadeToBlackBy(str_fade1[kring]); // gewone kleur
        ledstrip[i].fadeToBlackBy(glowfade);         // glow toepassen
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
