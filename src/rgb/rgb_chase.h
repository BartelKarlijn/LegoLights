#pragma once

void rgb_chase(uint8_t rgbnr) {
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
  uint16_t bri1, bri2, bri3;
  uint8_t  nr_leds =  rgbactive[rgbnr].stoprgb - rgbactive[rgbnr].startrgb + 1;
  uint8_t fase = 0;

  timeBezig = currentMillis - timer_rgb_aan[rgbnr];
  #define RGB_CHASE_FASE_NEWCYCLE   0
  #define RGB_CHASE_FASE_NEWLED     1
  #define RGB_CHASE_FASE_SAMELED    2
  #define RGB_CHASE_FASE_OFF        3

  // bereken fase
  if( timeBezig > (rgbactive[rgbnr].timeon + rgbactive[rgbnr].timeoff) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    fase = RGB_CHASE_FASE_NEWCYCLE;
  }
  else  if (timeBezig > rgbactive[rgbnr].timeon) { // einde van aan
    fase = RGB_CHASE_FASE_OFF;
  }
  else  if(currentMillis >  timer_rgb_effect[rgbnr]) {        //naar volgend spotje gaan
    fase = RGB_CHASE_FASE_NEWLED;
  }
  else {
    // gewoon verder doen, laat lampje maar branden
    fase = RGB_CHASE_FASE_SAMELED;
  }

  switch (fase) { 
    case RGB_CHASE_FASE_NEWCYCLE:
      timer_rgb_aan[rgbnr] = currentMillis; //reset timer
      timer_rgb_effect[rgbnr] = currentMillis + rgbactive[rgbnr].timeeffect;
      effectRgbNr[rgbnr] = 0;
      bri1 = rgbactive[rgbnr].bri1;
      bri2 = rgbactive[rgbnr].bri2;
      bri3 = rgbactive[rgbnr].bri3;
      break;
    case RGB_CHASE_FASE_OFF:
      bri1 = 0;
      bri2 = 0;
      bri3 = 0;
      break;
    case RGB_CHASE_FASE_SAMELED:
      bri1 = rgbactive[rgbnr].bri1;
      bri2 = rgbactive[rgbnr].bri2;
      bri3 = rgbactive[rgbnr].bri3;
      break;
    case RGB_CHASE_FASE_NEWLED:
      timer_rgb_effect[rgbnr] = currentMillis + rgbactive[rgbnr].timeeffect;  
      effectRgbNr[rgbnr] = effectRgbNr[rgbnr] + 1;
      bri1 = rgbactive[rgbnr].bri1;
      bri2 = rgbactive[rgbnr].bri2;
      bri3 = rgbactive[rgbnr].bri3;
      break;
    default:
      break;
  }

  // Pas juiste kleur toe
  if (rgbactive[rgbnr].seed > 0) {  // up
    for (uint8_t i = rgbactive[rgbnr].startrgb; i <= rgbactive[rgbnr].stoprgb; i++)  {
      if ( i < rgbactive[rgbnr].startrgb + effectRgbNr[rgbnr] ) {  // effect is al gepasseerd, dus kleur3
        rgbstrip[i] = CHSV(rgbactive[rgbnr].hue3, rgbactive[rgbnr].sat3, bri3);
      }
      else if( i == rgbactive[rgbnr].startrgb + effectRgbNr[rgbnr] ) { // effect is op dit ledje, dus kleur1
        rgbstrip[i] = CHSV(rgbactive[rgbnr].hue1, rgbactive[rgbnr].sat1, bri1);
      }
      else {                               // effect moet nog komen, dus kleur2
        rgbstrip[i] = CHSV(rgbactive[rgbnr].hue2, rgbactive[rgbnr].sat2, bri2);
      }
    }
  }
  else if (rgbactive[rgbnr].seed < 0) {  // down
    for (uint8_t i = rgbactive[rgbnr].stoprgb; i >= rgbactive[rgbnr].startrgb; i--)  {
      if ( i < rgbactive[rgbnr].stoprgb - effectRgbNr[rgbnr] ) {  // effect moet nog komen, dus kleur2
        rgbstrip[i] = CHSV(rgbactive[rgbnr].hue2, rgbactive[rgbnr].sat2, bri2);
      }
      else if( i == rgbactive[rgbnr].stoprgb - effectRgbNr[rgbnr] ) { // effect is op dit ledje, dus kleur1
        rgbstrip[i] = CHSV(rgbactive[rgbnr].hue1, rgbactive[rgbnr].sat1, bri1);
      }
      else {                               // effect is al gepasseerd, dus kleur3
        rgbstrip[i] = CHSV(rgbactive[rgbnr].hue3, rgbactive[rgbnr].sat3, bri3);
      }
    }
  }
  else { // up en down tegelijk.  we houden enkel rekening met kleur1 & 2
    for (uint8_t i = rgbactive[rgbnr].startrgb; i <= rgbactive[rgbnr].stoprgb; i++)  {
      if (( i == rgbactive[rgbnr].startrgb + effectRgbNr[rgbnr] )
       or ( i == rgbactive[rgbnr].stoprgb - effectRgbNr[rgbnr] )) {  // effect is op dit ledje, dus kleur1
        rgbstrip[i] = CHSV(rgbactive[rgbnr].hue1, rgbactive[rgbnr].sat1, bri1);
      }
      else {                               // effect moet nog komen, dus kleur2
        rgbstrip[i] = CHSV(rgbactive[rgbnr].hue2, rgbactive[rgbnr].sat2, bri2);
      }
    }
  }
}
