#pragma once

void str_fire(int kring) {
  int flamehue;
  int flamebright;
  unsigned long timeBezig;
 
  timeBezig = currentMillis - timer_str_aan[kring];
  // bereken mode (uit, up, down)
  if( timeBezig > (str_time1[kring] + str_time2[kring]) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_str_aan[kring] = currentMillis;      //reset timers
    timer_str_flicker[kring] = currentMillis;
    flamebright = random(255);
    idx_strflamehue[kring] = 0;
  }
  else  if (timeBezig > str_time1[kring]) { // einde van aan
    flamebright = 0;
  }
  else  if(timeBezig > timer_str_flicker[kring])  {//einde van flikering, begin een nieuwe
    idx_strflamehue[kring] = (idx_strflamehue[kring] + 1) % 4; //we hebben 4 kleuren, doe er eentje bij
    flamebright = random(255);
    timer_str_flicker[kring] = currentMillis; //reset flikkertimer
  }
  else {
    // gewoon verder doen
  }

// bereken kleur
   switch (idx_strflamehue[kring])
   {
   case 0:
    flamehue = str_hue1[kring];
    break;
   case 1:
    flamehue = str_hue2[kring];
    break;
   case 2:
    flamehue = str_hue3[kring];
    break;
   case 3:
    flamehue = str_hue4[kring];
    break;
   default:
    flamehue = 0;
    break;
   }

  for (size_t i = str_startled[kring]; i <= str_stopled[kring]; i++)  {
    // aan of uit zetten?
    if( ( (i - str_startled[kring]) % str_every[kring] ) == 0 ) {  // check every
      ledstrip[i] = CHSV(flamehue, 255, flamebright);
    }
    else {
      ledstrip[i] = CRGB::Black;
    }
  }
}
