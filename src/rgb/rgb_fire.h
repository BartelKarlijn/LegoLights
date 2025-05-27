#pragma once

void rgb_fire(int kringnr) {
  unsigned long timeBezig;
 
  timeBezig = currentMillis - timer_rgb_aan[kringnr];
  // bereken mode (uit, aan, flikker)
  if( timeBezig > (kring[kringnr].timeon + kring[kringnr].timeoff) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_rgb_aan[kringnr] = currentMillis;      //reset timers
    timer_rgb_effect[kringnr] = currentMillis + kring[kringnr].timeeffect;
    effectrgbbri[kringnr][0] = random(kring[kringnr].bri1);
    effectrgbhueidx[kringnr][0] = 0;
  }
  else  if (timeBezig > kring[kringnr].timeon) { // einde van aan
    effectrgbbri[kringnr][0] = 0;
  }
  else  if(currentMillis >  timer_rgb_effect[kringnr])  {//einde van flikering, begin een nieuwe
    effectrgbhueidx[kringnr][0] = (effectrgbhueidx[kringnr][0] + 1) % 4; //we hebben 4 kleuren, doe er eentje bij
    effectrgbbri[kringnr][0] = random(kring[kringnr].bri1);
    timer_rgb_effect[kringnr] = currentMillis + random(kring[kringnr].timeeffect) ; //reset flikkertimer
  }
  else {
    // gewoon verder doen, laat vlammetje maar branden
  }

// bereken kleur
   switch (effectrgbhueidx[kringnr][0])
   {
   case 0:
    effectrgbhue[kringnr][0] = kring[kringnr].hue1;
    effectrgbsat[kringnr][0] = kring[kringnr].sat1;
    break;
   case 1:
    effectrgbhue[kringnr][0] = kring[kringnr].hue2;
    effectrgbsat[kringnr][0] = kring[kringnr].sat2;
    break;
   case 2:
    effectrgbhue[kringnr][0] = kring[kringnr].hue3;
    effectrgbsat[kringnr][0] = kring[kringnr].sat3;
    break;
   case 3:
    effectrgbhue[kringnr][0] = kring[kringnr].hue4;
    effectrgbsat[kringnr][0] = kring[kringnr].sat4;
    break;
   default:
    effectrgbhue[kringnr][0] = 0;
    effectrgbsat[kringnr][0] = 0;
    break;
   }

  for (size_t i = kring[kringnr].startrgb; i <= kring[kringnr].stoprgb; i++)  {
    // aan of uit zetten?
    if( ( (i - kring[kringnr].startrgb) % kring[kringnr].every ) == 0 ) {  // check every
      rgbstrip[i] = CHSV(effectrgbhue[kringnr][0], effectrgbsat[kringnr][0], effectrgbbri[kringnr][0]);
    }
    else {
      rgbstrip[i] = CRGB::Black;
    }
  }
}
