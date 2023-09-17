#pragma once

void str_chase(int kringnr) {
  unsigned long timeBezig;
  bool flag_on;

  timeBezig = currentMillis - timer_str_aan[kringnr];
  // bereken mode (uit, up, down)
  if( timeBezig > (kring[kringnr].timeon + kring[kringnr].timeoff) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_str_aan[kringnr] = currentMillis;      //reset timers
    timer_str_effect[kringnr] = currentMillis + kring[kringnr].timeeffect;
    chasestrnr[kringnr][0] = kring[kringnr].startled;
    flag_on = true;
  }
  else  if (timeBezig > kring[kringnr].timeon) { // einde van aan
    flag_on = false;
  }
  else  if(currentMillis >  timer_str_effect[kringnr]) {        //naar volgend spotje gaan
    flag_on = true;
    timer_str_effect[kringnr] = currentMillis + kring[kringnr].timeeffect ; //reset flikkertimer
    chasestrnr[kringnr][0]++;
    if (chasestrnr[kringnr][0] > kring[kringnr].stopled) {
      chasestrnr[kringnr][0] = kring[kringnr].startled;
    }
  }
  else {
    // gewoon verder doen, laat lampje maar branden
    flag_on = true;
  }

  for (int i = kring[kringnr].startled; i <= kring[kringnr].stopled; i++)  {
    // aan of uit zetten?
    if (flag_on) {
      if( i == chasestrnr[kringnr][0] ) {
        ledstrip[i] = CHSV(kring[kringnr].hue1, kring[kringnr].sat1, kring[kringnr].bri1);
      }
      else {
        ledstrip[i] = CHSV(kring[kringnr].hue2, kring[kringnr].sat2, kring[kringnr].bri2);
      }
    }
    else {
      ledstrip[i] = CRGB::Black;
    }
  }
}
