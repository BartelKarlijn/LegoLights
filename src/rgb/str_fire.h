#pragma once

void str_fire(int kringnr) {
  unsigned long timeBezig;
 
  timeBezig = currentMillis - timer_str_aan[kringnr];
  // bereken mode (uit, aan, flikker)
  if( timeBezig > (kring[kringnr].timeon + kring[kringnr].timeoff) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_str_aan[kringnr] = currentMillis;      //reset timers
    timer_str_effect[kringnr] = currentMillis + kring[kringnr].timeeffect;
    effectstrbri[kringnr][0] = random(kring[kringnr].bri1);
    effectstrhueidx[kringnr][0] = 0;
  }
  else  if (timeBezig > kring[kringnr].timeon) { // einde van aan
    effectstrbri[kringnr][0] = 0;
  }
  else  if(currentMillis >  timer_str_effect[kringnr])  {//einde van flikering, begin een nieuwe
    effectstrhueidx[kringnr][0] = (effectstrhueidx[kringnr][0] + 1) % 4; //we hebben 4 kleuren, doe er eentje bij
    effectstrbri[kringnr][0] = random(kring[kringnr].bri1);
    timer_str_effect[kringnr] = currentMillis + random(kring[kringnr].timeeffect) ; //reset flikkertimer
  }
  else {
    // gewoon verder doen, laat vlammetje maar branden
  }

// bereken kleur
   switch (effectstrhueidx[kringnr][0])
   {
   case 0:
    effectstrhue[kringnr][0] = kring[kringnr].hue1;
    effectstrsat[kringnr][0] = kring[kringnr].sat1;
    break;
   case 1:
    effectstrhue[kringnr][0] = kring[kringnr].hue2;
    effectstrsat[kringnr][0] = kring[kringnr].sat2;
    break;
   case 2:
    effectstrhue[kringnr][0] = kring[kringnr].hue3;
    effectstrsat[kringnr][0] = kring[kringnr].sat3;
    break;
   case 3:
    effectstrhue[kringnr][0] = kring[kringnr].hue4;
    effectstrsat[kringnr][0] = kring[kringnr].sat4;
    break;
   default:
    effectstrhue[kringnr][0] = 0;
    effectstrsat[kringnr][0] = 0;
    break;
   }

  for (size_t i = kring[kringnr].startled; i <= kring[kringnr].stopled; i++)  {
    // aan of uit zetten?
    if( ( (i - kring[kringnr].startled) % kring[kringnr].every ) == 0 ) {  // check every
      ledstrip[i] = CHSV(effectstrhue[kringnr][0], effectstrsat[kringnr][0], effectstrbri[kringnr][0]);
    }
    else {
      ledstrip[i] = CRGB::Black;
    }
  }
}
