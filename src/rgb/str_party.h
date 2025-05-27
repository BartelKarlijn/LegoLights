#pragma once

void str_party(int kringnr) {
  unsigned long timeBezig;
  bool flag_on;
  int partyhue, partysat, partybri;

  timeBezig = currentMillis - timer_rgb_aan[kringnr];
  // bereken mode (uit, up, down)
  if( timeBezig > (kring[kringnr].timeon + kring[kringnr].timeoff) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_rgb_aan[kringnr] = currentMillis;      //reset timers
    timer_rgb_effect[kringnr] = currentMillis + kring[kringnr].timeeffect;
    chaseRgbNr[kringnr][0] = 0;
    flag_on = true;
  }
  else  if (timeBezig > kring[kringnr].timeon) { // einde van aan
    flag_on = false;
  }
  else  if(currentMillis >  timer_rgb_effect[kringnr]) {        //naar volgend spotje gaan
    flag_on = true;
    timer_rgb_effect[kringnr] = currentMillis + kring[kringnr].timeeffect ; //reset flikkertimer
    chaseRgbNr[kringnr][0] = (chaseRgbNr[kringnr][0] + 1) % 4;           //kleur vd party
  }
  else {
    // gewoon verder doen, laat lampje maar branden
    flag_on = true;
  }

// bepaal kleur
switch (chaseRgbNr[kringnr][0])
{
case 0:
  partyhue    = kring[kringnr].hue1;
  partysat    = kring[kringnr].sat1;
  partybri = kring[kringnr].bri1;
  break;
case 1:
  partyhue    = kring[kringnr].hue2;
  partysat    = kring[kringnr].sat2;
  partybri = kring[kringnr].bri2;
  break;
case 2:
  partyhue    = kring[kringnr].hue3;
  partysat    = kring[kringnr].sat3;
  partybri = kring[kringnr].bri3;
  break;
case 3:
  partyhue    = kring[kringnr].hue4;
  partysat    = kring[kringnr].sat4;
  partybri = kring[kringnr].bri4;
  break;
default:
  partyhue    = 0;
  partysat    = 0;
  partybri = 0;
  break;
}

  for (int i = kring[kringnr].startrgb; i <= kring[kringnr].stoprgb; i++)  {
    // aan of uit zetten?
    if (flag_on) {
      if( (i - kring[kringnr].startrgb) % ( 4 * kring[kringnr].every) == chaseRgbNr[kringnr][0] * kring[kringnr].every ) {
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
