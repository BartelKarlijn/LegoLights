#pragma once

uint8_t rgb_glow_map(uint8_t val1, uint8_t val2, uint8_t amountOf2){
  double newvalue;
  newvalue = val1 + (val2 - val1) * amountOf2 / 255;
  return newvalue;
}

void rgb_glow(size_t rgbnr) {
  // Er wordt doorheen de 4 kleuren van de glow gelopen.
  // seed wordt voorlopig? niet gebruikt
  // every geeft aan om de hoeveel lampjes er eentje aan gaat.


  // TimeEff : up of down cycle.  4 cycles in totaal
  // seed    : <0 : col1/2/3/4, seed aantal lampjes, random
  //           =0 : col1/2/3/4, hele strip
  //           >0 : col1/2/3/4, wacht x keer TimeEff
  unsigned long timeBezig;
  unsigned long timeGlow;
  unsigned long timeMap;
  unsigned long timeEffect;
  uint8_t bri_glow;
  CHSV    oldColor, targetColor, newColor;
  size_t hue, sat, bri;

  timeBezig  = currentMillis - timer_rgb_aan[rgbnr];
  timeGlow   = currentMillis - timer_rgb_effect[rgbnr];
  timeEffect = rgbactive[rgbnr].timeeffect;

  // bereken mode (uit, up, down)
  if( timeBezig > (rgbactive[rgbnr].timeon + rgbactive[rgbnr].timeoff) ) {   // up+down+uit = lang genoeg uit geweest.  Nu aanzetten
    newColor = CHSV(rgbactive[rgbnr].hue4, rgbactive[rgbnr].sat4, rgbactive[rgbnr].bri4 ); //we beginnen met 4e kleur, anders ziet vervolg er ineens gek uit
    timer_rgb_aan[rgbnr]    = currentMillis; //reset timer
    timer_rgb_effect[rgbnr] = currentMillis; //reset timer
  }
  else  if (timeGlow > rgbactive[rgbnr].timeon) { // lang genoeg aan geweest.  uitzetten
    newColor = CHSV(0, 255 ,0)  ;  //black
  }
  else  if (timeGlow > 4 * timeEffect) { // einde van 4e fase.  Terug naar 1
    timer_rgb_effect[rgbnr] = currentMillis; //reset timer
    newColor = CHSV(rgbactive[rgbnr].hue4, rgbactive[rgbnr].sat4, rgbactive[rgbnr].bri4);
  }
  else  if (timeGlow > 3 * timeEffect) { // op weg naar 4e kleur
    timeMap = map(timeGlow, 3 * timeEffect, 4 * timeEffect, 0, 255);
    hue = rgb_glow_map(rgbactive[rgbnr].hue3, rgbactive[rgbnr].hue4, timeMap);
    sat = rgb_glow_map(rgbactive[rgbnr].sat3, rgbactive[rgbnr].sat4, timeMap);
    bri = rgb_glow_map(rgbactive[rgbnr].bri3, rgbactive[rgbnr].bri4, timeMap);
    newColor = CHSV(hue, sat, bri);
  }
  else  if (timeGlow > 2 * timeEffect) { // op weg naar 3e kleur
    timeMap = map(timeGlow, 2 * timeEffect, 3 * timeEffect, 0, 255);
    hue = rgb_glow_map(rgbactive[rgbnr].hue2, rgbactive[rgbnr].hue3, timeMap);
    sat = rgb_glow_map(rgbactive[rgbnr].sat2, rgbactive[rgbnr].sat3, timeMap);
    bri = rgb_glow_map(rgbactive[rgbnr].bri2, rgbactive[rgbnr].bri3, timeMap);
    newColor = CHSV(hue, sat, bri);
  }
  else  if (timeGlow > timeEffect) { // op weg naar 2e kleur
    timeMap = map(timeGlow, timeEffect, 2 * timeEffect, 0, 255);
    hue = rgb_glow_map(rgbactive[rgbnr].hue1, rgbactive[rgbnr].hue2, timeMap);
    sat = rgb_glow_map(rgbactive[rgbnr].sat1, rgbactive[rgbnr].sat2, timeMap);
    bri = rgb_glow_map(rgbactive[rgbnr].bri1, rgbactive[rgbnr].bri2, timeMap);
    newColor = CHSV(hue, sat, bri);
  }
  else {     //op weg naar 1e kleur
    timeMap = map(timeGlow, 0, timeEffect, 0, 255);
    hue = rgb_glow_map(rgbactive[rgbnr].hue4, rgbactive[rgbnr].hue1, timeMap);
    sat = rgb_glow_map(rgbactive[rgbnr].sat1, rgbactive[rgbnr].sat1, timeMap);
    bri = rgb_glow_map(rgbactive[rgbnr].bri4, rgbactive[rgbnr].bri1, timeMap);
    newColor = CHSV(hue, sat, bri);
  }

  for (size_t i = rgbactive[rgbnr].startrgb; i <= rgbactive[rgbnr].stoprgb; i++)
  {
    // aan of uit zetten?
    if( ( (i - rgbactive[rgbnr].startrgb) % rgbactive[rgbnr].every ) == 0 ) {  // check every
      rgbstrip[i] = newColor;
    }
    else {
      rgbstrip[i] = CRGB::Black;
    }
  }
}
