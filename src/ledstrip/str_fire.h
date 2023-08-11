#pragma once

void str_fire(int kring) {
  bool fl_on;
  int flamehueidx;
  int flamehue;
  int flamebright;
  unsigned long timeBezig;
 
  timeBezig = currentMillis - timer_str_aan[kring];
  // bereken mode (uit, up, down)
  if( timeBezig > (str_time1[kring] + str_time2[kring]) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    fl_on = true;
    flamehueidx = 1;
    timer_str_aan[kring] = currentMillis; //reset timer
    flamebright = random(255);
  }
  else  if (timeBezig > str_time1[kring]) { // einde van aan
    fl_on = false;
  }
  else  if(timeBezig > timer_str_flicker[kring])  {//einde van flikering, begin een nieuwe
    fl_on = true;
    flamehueidx = (flamehue + 1) % 4; //we hebben 4 kleuren
    flamebright = random(255);
  }

// bereken kleur
   switch (flamehueidx)
   {
   case 1:
    flamehue = str_hue1[kring];
    break;
   case 2:
    flamehue = str_hue2[kring];
    break;
   case 3:
    flamehue = str_hue3[kring];
    break;
   case 4:
    flamehue = str_hue4[kring];
    break;
   default:
    flamehue = 0;
    break;
   }

  for (size_t i = str_startled[kring]; i <= str_stopled[kring]; i++)
  {
    // aan of uit zetten?
    if (fl_on) {
      if( ( (i - str_startled[kring]) % str_every[kring] ) == 0 ) {  // check every
        ledstrip[i] = CHSV(flamehue, 255, flamebright);
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
