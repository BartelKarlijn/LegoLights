#pragma once

uint8_t str_glow_map(uint8_t val1, uint8_t val2, uint8_t amountOf2){
  double newvalue;
  newvalue = val1 + (val2 - val1) * amountOf2 / 255;
  return newvalue;
}

void str_glow(int kringnr) {
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
  int hue, sat, bri;

  timeBezig  = currentMillis - timer_str_aan[kringnr];
  timeGlow   = currentMillis - timer_str_effect[kringnr];
  timeEffect = kring[kringnr].timeeffect;

  // bereken mode (uit, up, down)
  if( timeBezig > (kring[kringnr].timeon + kring[kringnr].timeoff) ) {   // up+down+uit = lang genoeg uit geweest.  Nu aanzetten
    newColor = CHSV(kring[kringnr].hue4, kring[kringnr].sat4, kring[kringnr].bri4 ); //we beginnen met 4e kleur, anders ziet vervolg er ineens gek uit
    timer_str_aan[kringnr]    = currentMillis; //reset timer
    timer_str_effect[kringnr] = currentMillis; //reset timer
  }
  else  if (timeGlow > kring[kringnr].timeon) { // lang genoeg aan geweest.  uitzetten
    newColor = CHSV(0, 255 ,0)  ;  //black
  }
  else  if (timeGlow > 4 * timeEffect) { // einde van 4e fase.  Terug naar 1
    timer_str_effect[kringnr] = currentMillis; //reset timer
    newColor = CHSV(kring[kringnr].hue4, kring[kringnr].sat4, kring[kringnr].bri4);
  }
  else  if (timeGlow > 3 * timeEffect) { // op weg naar 4e kleur
    timeMap = map(timeGlow, 3 * timeEffect, 4 * timeEffect, 0, 255);
    hue = str_glow_map(kring[kringnr].hue3, kring[kringnr].hue4, timeMap);
    sat = str_glow_map(kring[kringnr].sat3, kring[kringnr].sat4, timeMap);
    bri = str_glow_map(kring[kringnr].bri3, kring[kringnr].bri4, timeMap);
    newColor = CHSV(hue, sat, bri);
  }
  else  if (timeGlow > 2 * timeEffect) { // op weg naar 3e kleur
    timeMap = map(timeGlow, 2 * timeEffect, 3 * timeEffect, 0, 255);
    hue = str_glow_map(kring[kringnr].hue2, kring[kringnr].hue3, timeMap);
    sat = str_glow_map(kring[kringnr].sat2, kring[kringnr].sat3, timeMap);
    bri = str_glow_map(kring[kringnr].bri2, kring[kringnr].bri3, timeMap);
    newColor = CHSV(hue, sat, bri);
  }
  else  if (timeGlow > timeEffect) { // op weg naar 2e kleur
    timeMap = map(timeGlow, timeEffect, 2 * timeEffect, 0, 255);
    hue = str_glow_map(kring[kringnr].hue1, kring[kringnr].hue2, timeMap);
    sat = str_glow_map(kring[kringnr].sat1, kring[kringnr].sat2, timeMap);
    bri = str_glow_map(kring[kringnr].bri1, kring[kringnr].bri2, timeMap);
    newColor = CHSV(hue, sat, bri);
  }
  else {     //op weg naar 1e kleur
    timeMap = map(timeGlow, 0, timeEffect, 0, 255);
    hue = str_glow_map(kring[kringnr].hue4, kring[kringnr].hue1, timeMap);
    sat = str_glow_map(kring[kringnr].sat1, kring[kringnr].sat1, timeMap);
    bri = str_glow_map(kring[kringnr].bri4, kring[kringnr].bri1, timeMap);
    newColor = CHSV(hue, sat, bri);
  }

  for (int i = kring[kringnr].startled; i <= kring[kringnr].stopled; i++)
  {
    // aan of uit zetten?
    if( ( (i - kring[kringnr].startled) % kring[kringnr].every ) == 0 ) {  // check every
      ledstrip[i] = newColor;
    }
    else {
      ledstrip[i] = CRGB::Black;
    }
  }
}
