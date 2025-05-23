#pragma once

void str_party(int kringnr) {
  unsigned long timeBezig;
  bool flag_on;
  int partyhue, partysat, partybri;

  timeBezig = currentMillis - timer_str_aan[kringnr];
  // bereken mode (uit, up, down)
  if( timeBezig > (kring[kringnr].timeon + kring[kringnr].timeoff) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_str_aan[kringnr] = currentMillis;      //reset timers
    timer_str_effect[kringnr] = currentMillis + kring[kringnr].timeeffect;
    chasestrnr[kringnr][0] = 0;
    flag_on = true;
  }
  else  if (timeBezig > kring[kringnr].timeon) { // einde van aan
    flag_on = false;
  }
  else  if(currentMillis >  timer_str_effect[kringnr]) {        //naar volgend spotje gaan
    flag_on = true;
    timer_str_effect[kringnr] = currentMillis + kring[kringnr].timeeffect ; //reset flikkertimer
    chasestrnr[kringnr][0] = (chasestrnr[kringnr][0] + 1) % 4;           //kleur vd party
  }
  else {
    // gewoon verder doen, laat lampje maar branden
    flag_on = true;
  }

// bepaal kleur
switch (chasestrnr[kringnr][0])
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

  for (int i = kring[kringnr].startled; i <= kring[kringnr].stopled; i++)  {
    // aan of uit zetten?
    if (flag_on) {
      if( (i - kring[kringnr].startled) % ( 4 * kring[kringnr].every) == chasestrnr[kringnr][0] * kring[kringnr].every ) {
        ledstrip[i] = CHSV(partyhue, partysat, partybri);
      }
      else {
        ledstrip[i] = CRGB::Black;
      }
    }
    else {
      ledstrip[i] = CRGB::Black;
    }
  }
}
