#pragma once

void str_fire(int kringnr) {
  unsigned long timeBezig;
 
  timeBezig = currentMillis - timer_str_aan[kringnr];
  // bereken mode (uit, aan, flikker)
  if( timeBezig > (kring[kringnr].timeon + kring[kringnr].timeoff) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_str_aan[kringnr] = currentMillis;      //reset timers
    timer_str_flicker[kringnr] = currentMillis + kring[kringnr].timeeffect;
    flamestrbright[kringnr] = random(kring[kringnr].bright1);
    flamestrhueidx[kringnr] = 0;
  }
  else  if (timeBezig > kring[kringnr].timeon) { // einde van aan
    flamestrbright[kringnr] = 0;
  }
  else  if(currentMillis >  timer_str_flicker[kringnr])  {//einde van flikering, begin een nieuwe
    flamestrhueidx[kringnr] = (flamestrhueidx[kringnr] + 1) % 4; //we hebben 4 kleuren, doe er eentje bij
    flamestrbright[kringnr] = random(kring[kringnr].bright1);
    timer_str_flicker[kringnr] = currentMillis + random(kring[kringnr].timeeffect) ; //reset flikkertimer
  }
  else {
    // gewoon verder doen, laat vlammetje maar branden
  }

// bereken kleur
   switch (flamestrhueidx[kringnr])
   {
   case 0:
    flamestrhue[kringnr] = kring[kringnr].hue1;
    flamestrsat[kringnr] = kring[kringnr].sat1;
    break;
   case 1:
    flamestrhue[kringnr] = kring[kringnr].hue2;
    flamestrsat[kringnr] = kring[kringnr].sat2;
    break;
   case 2:
    flamestrhue[kringnr] = kring[kringnr].hue3;
    flamestrsat[kringnr] = kring[kringnr].sat3;
    break;
   case 3:
    flamestrhue[kringnr] = kring[kringnr].hue4;
    flamestrsat[kringnr] = kring[kringnr].sat4;
    break;
   default:
    flamestrhue[kringnr] = 0;
    flamestrsat[kringnr] = 0;
    break;
   }

  for (size_t i = kring[kringnr].startled; i <= kring[kringnr].stopled; i++)  {
    // aan of uit zetten?
    if( ( (i - kring[kringnr].startled) % kring[kringnr].every ) == 0 ) {  // check every
      ledstrip[i] = CHSV(flamestrhue[kringnr], flamestrsat[kringnr], flamestrbright[kringnr]);
    }
    else {
      ledstrip[i] = CRGB::Black;
    }
  }
}
