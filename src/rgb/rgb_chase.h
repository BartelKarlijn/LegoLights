#pragma once

void rgb_chase(size_t kringnr) {
  // seed: -4..-1 : 1..4 lichtjes die down gaan
  // seed: 0      : lichtje up en eentje down
  // seed: +1..+4 : 1..4 lichtjes up gaan
  unsigned long timeBezig;
  bool flag_on;
  size_t  nr_leds =  kring[kringnr].stoprgb - kring[kringnr].startrgb + 1;
  size_t  spacing;
  
  if (kring[kringnr].seed = 0) {
    spacing = nr_leds;
  } else {
    spacing = nr_leds / abs(kring[kringnr].seed);
  }
  timeBezig = currentMillis - timer_rgb_aan[kringnr];
  

  // bereken mode (uit, up, down)
  if( timeBezig > (kring[kringnr].timeon + kring[kringnr].timeoff) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_rgb_aan[kringnr] = currentMillis;      //reset timers
    timer_rgb_effect[kringnr] = currentMillis + kring[kringnr].timeeffect;
    chaseRgbNr[kringnr][0] = kring[kringnr].startrgb;
    flag_on = true;
  }
  else  if (timeBezig > kring[kringnr].timeon) { // einde van aan
    flag_on = false;
  }
  else  if(currentMillis >  timer_rgb_effect[kringnr]) {        //naar volgend spotje gaan
    flag_on = true;
    timer_rgb_effect[kringnr] = currentMillis + kring[kringnr].timeeffect ; //reset flikkertimer
    chaseRgbNr[kringnr][0]++;
    if (chaseRgbNr[kringnr][0] > kring[kringnr].stoprgb) {
      chaseRgbNr[kringnr][0] = kring[kringnr].startrgb;
    }
  }
  else {
    // gewoon verder doen, laat lampje maar branden
    flag_on = true;
  }

  for (size_t i = kring[kringnr].startrgb; i <= kring[kringnr].stoprgb; i++)  {
    // aan of uit zetten?
    if (flag_on) {

      if( i == chaseRgbNr[kringnr][0] ) {
        rgbstrip[i] = CHSV(kring[kringnr].hue1, kring[kringnr].sat1, kring[kringnr].bri1);
      }
      else {
        rgbstrip[i] = CHSV(kring[kringnr].hue2, kring[kringnr].sat2, kring[kringnr].bri2);
      }
    }
    else {
      rgbstrip[i] = CRGB::Black;
    }
  }
}
