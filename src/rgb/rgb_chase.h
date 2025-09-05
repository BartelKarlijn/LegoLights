#pragma once

void rgb_chase(size_t rgbnr) {
  // we gebruiken 3 kleuren: 
  //  - kleur1 = beweegt, 
  //  - kleur2 = achtergrond (als we aan nieuwe iteratie beginnen)
  //  - kleur3 = kleur die gezet wordt nadat kleur1 dat ledje gepasseerd is. (vooral nuttig voor een pinker)
  // timeeffect geeft aan hoe snel kleur1 beweegt.
  // dit blijft doorgaan tot timeon afgelopen is, dan weer uit.
  // voorlopig doen we niets met seed en every.
  
  // seed: -4..-1 : 1..4 lichtjes die down gaan
  // seed: 0      : lichtje up en eentje down
  // seed: +1..+4 : 1..4 lichtjes up gaan
  unsigned long timeBezig;
  bool flag_on;
  size_t  nr_leds =  rgbactive[rgbnr].stoprgb - rgbactive[rgbnr].startrgb + 1;
  size_t  spacing;
  
  if (rgbactive[rgbnr].seed = 0) {  //voorlopig? doen we niets met spacing, seed of every...
    spacing = nr_leds;
  } else {
    spacing = nr_leds / abs(rgbactive[rgbnr].seed);
  }
  timeBezig = currentMillis - timer_rgb_aan[rgbnr];
  

  // bereken mode (uit, up, down)
  if( timeBezig > (rgbactive[rgbnr].timeon + rgbactive[rgbnr].timeoff) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_rgb_aan[rgbnr] = currentMillis;      //reset timers
    timer_rgb_effect[rgbnr] = currentMillis + rgbactive[rgbnr].timeeffect;
    chaseRgbNr[rgbnr][0] = rgbactive[rgbnr].startrgb;
    flag_on = true;
  }
  else  if (timeBezig > rgbactive[rgbnr].timeon) { // einde van aan
    flag_on = false;
  }
  else  if(currentMillis >  timer_rgb_effect[rgbnr]) {        //naar volgend spotje gaan
    flag_on = true;
    timer_rgb_effect[rgbnr] = currentMillis + rgbactive[rgbnr].timeeffect ; //reset flikkertimer
    chaseRgbNr[rgbnr][0]++;
    if (chaseRgbNr[rgbnr][0] > rgbactive[rgbnr].stoprgb) {
      chaseRgbNr[rgbnr][0] = rgbactive[rgbnr].startrgb;
    }
  }
  else {
    // gewoon verder doen, laat lampje maar branden
    flag_on = true;
  }

  for (size_t i = rgbactive[rgbnr].startrgb; i <= rgbactive[rgbnr].stoprgb; i++)  {
    // aan of uit zetten?
    if (flag_on) {

      if( i == chaseRgbNr[rgbnr][0] ) {
        rgbstrip[i] = CHSV(rgbactive[rgbnr].hue1, rgbactive[rgbnr].sat1, rgbactive[rgbnr].bri1);
      }
      else {
        rgbstrip[i] = CHSV(rgbactive[rgbnr].hue2, rgbactive[rgbnr].sat2, rgbactive[rgbnr].bri2);
      }
    }
    else {
      rgbstrip[i] = CRGB::Black;
    }
  }
}
