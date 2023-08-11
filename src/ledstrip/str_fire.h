#pragma once

void str_fire(int kring) {
  bool fl_on;
  int flamecolor;
  unsigned long timeBezig;

timeBezig = currentMillis - timer_str_aan[kring];
// bereken mode (uit, up, down)
  if( timeBezig > (str_time1[kring] + str_time2[kring]) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    fl_on = true;
    flamecolor = 1;
    timer_str_aan[kring] = currentMillis; //reset timer
  }
  else  if (timeBezig > str_time1[kring]) { // einde van aan
    fl_on = false;
  }
  else {     //nog tijdje up te flikeren.
    fl_on = true;
    flamecolor = (flamecolor + 1) % 4; //we hebben 4 kleuren
  }

// bereken level
//  if( fl_on and fl_up ){
//    glowfade = map(timeBezig, 0, str_time1[kring], 0, 255 );
//  }
//  else {
//    glowfade = map(timeBezig, 0, str_time1[kring], 255, 0 );
//  }

  for (size_t i = str_startled[kring]; i <= str_stopled[kring]; i++)
  {
    // aan of uit zetten?
    if (fl_on) {
      if( ( (i - str_startled[kring]) % str_every[kring] ) == 0 ) {  // check every
        ledstrip[i] = str_color1[kring];
        ledstrip[i].fadeToBlackBy(str_fade1[kring]); // gewone kleur
//        ledstrip[i].fadeToBlackBy(glowfade);         // glow toepassen
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
