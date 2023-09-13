#pragma once

void str_fire(int kringnr) {
  unsigned long timeBezig;
 
  timeBezig = currentMillis - timer_str_aan[kringnr];
  // bereken mode (uit, aan, flikker)
  if( timeBezig > (kring[kringnr].timeon + kring[kringnr].timeoff) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_str_aan[kringnr] = currentMillis;      //reset timers
    timer_str_effect[kringnr] = currentMillis + kring[kringnr].timeeffect;
    effectstrbright[kringnr] = random(kring[kringnr].bright1);
    effectstrhueidx[kringnr] = 0;
  }
  else  if (timeBezig > kring[kringnr].timeon) { // einde van aan
    effectstrbright[kringnr] = 0;
  }
  else  if(currentMillis >  timer_str_effect[kringnr])  {//einde van flikering, begin een nieuwe
    effectstrhueidx[kringnr] = (effectstrhueidx[kringnr] + 1) % 4; //we hebben 4 kleuren, doe er eentje bij
    effectstrbright[kringnr] = random(kring[kringnr].bright1);
    timer_str_effect[kringnr] = currentMillis + random(kring[kringnr].timeeffect) ; //reset flikkertimer
  }
  else {
    // gewoon verder doen, laat vlammetje maar branden
  }

// bereken kleur
   switch (effectstrhueidx[kringnr])
   {
   case 0:
    effectstrhue[kringnr] = kring[kringnr].hue1;
    effectstrsat[kringnr] = kring[kringnr].sat1;
    break;
   case 1:
    effectstrhue[kringnr] = kring[kringnr].hue2;
    effectstrsat[kringnr] = kring[kringnr].sat2;
    break;
   case 2:
    effectstrhue[kringnr] = kring[kringnr].hue3;
    effectstrsat[kringnr] = kring[kringnr].sat3;
    break;
   case 3:
    effectstrhue[kringnr] = kring[kringnr].hue4;
    effectstrsat[kringnr] = kring[kringnr].sat4;
    break;
   default:
    effectstrhue[kringnr] = 0;
    effectstrsat[kringnr] = 0;
    break;
   }

  for (size_t i = kring[kringnr].startled; i <= kring[kringnr].stopled; i++)  {
    // aan of uit zetten?
    if( ( (i - kring[kringnr].startled) % kring[kringnr].every ) == 0 ) {  // check every
      ledstrip[i] = CHSV(effectstrhue[kringnr], effectstrsat[kringnr], effectstrbright[kringnr]);
    }
    else {
      ledstrip[i] = CRGB::Black;
    }
  }
}
