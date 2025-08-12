#pragma once

void rgb_party(size_t rgbnr) {
  unsigned long timeBezig;
  bool flag_on;
  size_t partyhue, partysat, partybri;

  timeBezig = currentMillis - timer_rgb_aan[rgbnr];
  // bereken mode (uit, up, down)
  if( timeBezig > (rgbactive[rgbnr].timeon + rgbactive[rgbnr].timeoff) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_rgb_aan[rgbnr] = currentMillis;      //reset timers
    timer_rgb_effect[rgbnr] = currentMillis + rgbactive[rgbnr].timeeffect;
    chaseRgbNr[rgbnr][0] = 0;
    flag_on = true;
  }
  else  if (timeBezig > rgbactive[rgbnr].timeon) { // einde van aan
    flag_on = false;
  }
  else  if(currentMillis >  timer_rgb_effect[rgbnr]) {        //naar volgend spotje gaan
    flag_on = true;
    timer_rgb_effect[rgbnr] = currentMillis + rgbactive[rgbnr].timeeffect ; //reset flikkertimer
    chaseRgbNr[rgbnr][0] = (chaseRgbNr[rgbnr][0] + 1) % 4;           //kleur vd party
  }
  else {
    // gewoon verder doen, laat lampje maar branden
    flag_on = true;
  }

// bepaal kleur
switch (chaseRgbNr[rgbnr][0])
{
case 0:
  partyhue    = rgbactive[rgbnr].hue1;
  partysat    = rgbactive[rgbnr].sat1;
  partybri = rgbactive[rgbnr].bri1;
  break;
case 1:
  partyhue    = rgbactive[rgbnr].hue2;
  partysat    = rgbactive[rgbnr].sat2;
  partybri = rgbactive[rgbnr].bri2;
  break;
case 2:
  partyhue    = rgbactive[rgbnr].hue3;
  partysat    = rgbactive[rgbnr].sat3;
  partybri = rgbactive[rgbnr].bri3;
  break;
case 3:
  partyhue    = rgbactive[rgbnr].hue4;
  partysat    = rgbactive[rgbnr].sat4;
  partybri = rgbactive[rgbnr].bri4;
  break;
default:
  partyhue    = 0;
  partysat    = 0;
  partybri = 0;
  break;
}

  for (size_t i = rgbactive[rgbnr].startrgb; i <= rgbactive[rgbnr].stoprgb; i++)  {
    // aan of uit zetten?
    if (flag_on) {
      if( (i - rgbactive[rgbnr].startrgb) % ( 4 * rgbactive[rgbnr].every) == chaseRgbNr[rgbnr][0] * rgbactive[rgbnr].every ) {
        rgbstrip[i] = CHSV(partyhue, partysat, partybri);
      }
      else {
        rgbstrip[i] = CRGB::Black;
      }
    }
    else {
      rgbstrip[i] = CRGB::Black;
    }
  }
}
