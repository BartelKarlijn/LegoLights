#pragma once

void str_glow(int kringnr) {
  // TimeEff : up of down cycle.  4 cycles in totaal
  // seed    : <0 : col1/2/3/4, seed aantal lampjes, random
  //           =0 : col1/2/3/4, hele strip
  //           >0 : col1/2/3/4, wacht x keer TimeEff
  unsigned long timeBezig;
  unsigned long timeGlow;
  unsigned long timeMap;
  unsigned long timeEffect;
  uint8_t brightn_glow;
  fract8  amountOftarget;
  CHSV    oldColor, targetColor, newColor;

  timeBezig  = currentMillis - timer_str_aan[kringnr];
  timeGlow   = currentMillis - timer_str_effect[kringnr];
  timeEffect = kring[kringnr].timeeffect;

  // bereken mode (uit, up, down)
  if( timeBezig > (2 * kring[kringnr].timeon + kring[kringnr].timeoff) ) {   // up+down+uit = lang genoeg uit geweest.  Nu aanzetten
    newColor = CHSV(kring[kringnr].hue4, kring[kringnr].sat4, kring[kringnr].bright4 ); //we beginnen met 4e kleur, anders ziet vervolg er ineens gek uit
    timer_str_aan[kringnr]    = currentMillis; //reset timer
    timer_str_effect[kringnr] = currentMillis; //reset timer
  }
  else  if (timeBezig > timeGlow + 4 * timeEffect) { // einde van 4e fase.  Terug naar 1
    timer_str_effect[kringnr] = currentMillis; //reset timer
    newColor = CHSV(kring[kringnr].hue4, kring[kringnr].sat4, kring[kringnr].bright4);
  }
  else  if (timeBezig > timeGlow + 3 * timeEffect) { // op weg naar 4e kleur
    oldColor    = CHSV(kring[kringnr].hue3, kring[kringnr].sat3, kring[kringnr].bright3);
    targetColor = CHSV(kring[kringnr].hue4, kring[kringnr].sat4, kring[kringnr].bright4);
    timeMap = map(timeBezig, timeGlow + 3 * timeEffect, timeGlow + 4 * timeEffect, 255,  1);  //1: we willen geen deling door 0 hierna
    amountOftarget = 1 / timeMap;
    newColor    = blend( oldColor, newColor, amountOftarget, SHORTEST_HUES);
  }
  else  if (timeBezig > timeGlow + 2 * timeEffect) { // op weg naar 3e kleur
    oldColor    = CHSV(kring[kringnr].hue2, kring[kringnr].sat2, kring[kringnr].bright2);
    targetColor = CHSV(kring[kringnr].hue3, kring[kringnr].sat3, kring[kringnr].bright3);
    timeMap = map(timeBezig, timeGlow + 2 * timeEffect, timeGlow + 3 * timeEffect, 255, 1);
    amountOftarget = 1 / timeMap;
    newColor    = blend( oldColor, newColor, amountOftarget, SHORTEST_HUES);
  }
  else  if (timeBezig > timeGlow + timeEffect) { // op weg naar 2e kleur
    oldColor    = CHSV(kring[kringnr].hue1, kring[kringnr].sat1, kring[kringnr].bright1);
    targetColor = CHSV(kring[kringnr].hue2, kring[kringnr].sat2, kring[kringnr].bright2);
    timeMap = map(timeBezig, timeGlow + 1 * timeEffect, timeGlow + 2 * timeEffect, 255, 1);
    amountOftarget = 1 / timeMap;
    newColor    = blend( oldColor, newColor, amountOftarget, SHORTEST_HUES);
  }
  else {     //op weg naar 1e kleur
    oldColor    = CHSV(kring[kringnr].hue4, kring[kringnr].sat4, kring[kringnr].bright4);
    targetColor = CHSV(kring[kringnr].hue1, kring[kringnr].sat1, kring[kringnr].bright1);
    timeMap = map(timeBezig, timeGlow + 0 * timeEffect, timeGlow + 1 * timeEffect, 255, 1);
    amountOftarget = 1 / timeMap;
    newColor    = blend( oldColor, newColor, amountOftarget, SHORTEST_HUES);
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
