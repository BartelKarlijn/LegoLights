#pragma once

void rgb_aan(size_t rgbnr) {
  // Aan/uit zetten van RGB strip
  // We gebruiken 2 kleuren.  kleur1 begint, en komt elke every terug.  Daartussen kleur2.
  // seed geeft aan waar de eerste kleur begint.  Kan positief of negatief zijn.

  unsigned long timeBezig;
  uint16_t bri1, bri2;
  uint8_t fase = 0;

  timeBezig = currentMillis - timer_rgb_aan[rgbnr];
  #define RGB_AAN_FASE_NEWCYCLE   0
  #define RGB_AAN_FASE_RAMPUP     1
  #define RGB_AAN_FASE_FULLON     2
  #define RGB_AAN_FASE_RAMPDOWN   3
  #define RGB_AAN_FASE_OFF        4

  // bepaal fase; dit moet van achter naar voor gebeuren
  if( timeBezig > (rgbactive[rgbnr].timeon + rgbactive[rgbnr].timeoff) ) {   // lang genoeg uit geweest.  Nu aanzetten
    fase = RGB_AAN_FASE_NEWCYCLE;
  }
  else  if (timeBezig > rgbactive[rgbnr].timeon) { // lang genoeg aan geweest
    fase = RGB_AAN_FASE_OFF;
  }
  else  if ((timeBezig > rgbactive[rgbnr].timeon - rgbactive[rgbnr].timeeffect)
         && (timeBezig > rgbactive[rgbnr].timeeffect ) ) { // checken dat we geen t.effect wel groot genoeg is.
    fase = RGB_AAN_FASE_RAMPDOWN;
  }
  else  if ((timeBezig > rgbactive[rgbnr].timeeffect ) ) { 
    fase = RGB_AAN_FASE_FULLON;
  }
  else {     
    fase = RGB_AAN_FASE_RAMPUP;
  }

  // Nu uitvogelen welke kleur enz te gebruiken
  switch (fase)
  {
  case RGB_AAN_FASE_NEWCYCLE:
    timer_rgb_aan[rgbnr] = currentMillis; //reset timer
    bri1 = 0;
    bri2 = 0;
    break;
  case RGB_AAN_FASE_FULLON:
    bri1 = rgbactive[rgbnr].bri1;
    bri2 = rgbactive[rgbnr].bri2;
    break;
  case RGB_AAN_FASE_OFF:
    bri1 = 0;
    bri2 = 0;
    break;
  case RGB_AAN_FASE_RAMPUP:
    bri1 = map(timeBezig, 0, rgbactive[rgbnr].timeeffect, 0, rgbactive[rgbnr].bri1);
    bri2 = map(timeBezig, 0, rgbactive[rgbnr].timeeffect, 0, rgbactive[rgbnr].bri2);
    break;
  case RGB_AAN_FASE_RAMPDOWN:
    bri1 = map(timeBezig, rgbactive[rgbnr].timeon - rgbactive[rgbnr].timeeffect, rgbactive[rgbnr].timeon, rgbactive[rgbnr].bri1, 0);
    bri2 = map(timeBezig, rgbactive[rgbnr].timeon - rgbactive[rgbnr].timeeffect, rgbactive[rgbnr].timeon, rgbactive[rgbnr].bri2, 0);
    break;
  default:
    bri1 = 0;
    bri2 = 0;
    break;
  }
  
  // Tenslotte alle ledjes de juiste kleur geven  
  for (size_t i = rgbactive[rgbnr].startrgb; i <= rgbactive[rgbnr].stoprgb; i++) {
    if( ( (i - rgbactive[rgbnr].startrgb + rgbactive[rgbnr].seed + 30*rgbactive[rgbnr].every) % rgbactive[rgbnr].every ) == 0 ) {  // check every.  Aangezien negatieve waarden kunnen voorkomen, tellen we er 30 x every bij op om zeker positieve waarden te hebben
      rgbstrip[i] = CHSV(rgbactive[rgbnr].hue1, rgbactive[rgbnr].sat1, bri1 );
    }
    else {
      rgbstrip[i] = CHSV(rgbactive[rgbnr].hue2, rgbactive[rgbnr].sat2, bri2 );
    }
  }
  
}
