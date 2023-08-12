#pragma once

void str_party(int kring) {
  unsigned long timeBezig;
  bool flag_on;
  int partyhue, partysat, partybright;

  timeBezig = currentMillis - timer_str_aan[kring];
  // bereken mode (uit, up, down)
  if( timeBezig > (str_time1[kring] + str_time2[kring]) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_str_aan[kring] = currentMillis;      //reset timers
    timer_str_flicker[kring] = currentMillis + str_tim_flick[kring];
    chasestrnr[kring] = 0;
    flag_on = true;
  }
  else  if (timeBezig > str_time1[kring]) { // einde van aan
    flag_on = false;
  }
  else  if(currentMillis >  timer_str_flicker[kring]) {        //naar volgend spotje gaan
    flag_on = true;
    timer_str_flicker[kring] = currentMillis + str_tim_flick[kring] ; //reset flikkertimer
    chasestrnr[kring] = (chasestrnr[kring] + 1) % 4;           //kleur vd party
  }
  else {
    // gewoon verder doen, laat lampje maar branden
    flag_on = true;
  }

// bepaal kleur
switch (chasestrnr[kring])
{
case 0:
  partyhue    = str_hue1[kring];
  partysat    = str_sat1[kring];
  partybright = str_bright1[kring];
  break;
case 1:
  partyhue    = str_hue2[kring];
  partysat    = str_sat2[kring];
  partybright = str_bright2[kring];
  break;
case 2:
  partyhue    = str_hue3[kring];
  partysat    = str_sat3[kring];
  partybright = str_bright3[kring];
  break;
case 3:
  partyhue    = str_hue4[kring];
  partysat    = str_sat4[kring];
  partybright = str_bright4[kring];
  break;
default:
  partyhue    = 0;
  partysat    = 0;
  partybright = 0;
  break;
}

  for (size_t i = str_startled[kring]; i <= str_stopled[kring]; i++)  {
    // aan of uit zetten?
    if (flag_on) {
      if( (i - str_startled[kring]) % ( 4 * str_every[kring]) == chasestrnr[kring] * str_every[kring] ) {
        ledstrip[i] = CHSV(partyhue, partysat, partybright);
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
