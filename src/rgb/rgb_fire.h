#pragma once

void rgb_fire(size_t rgbnr) {
  unsigned long timeBezig;
  // we gebruiken 4 kleuren en het vlammetje flikkert in deze kleuren.
  // time effect geeft aan hoe snel het vlammetje flikkert, al zit er een randomizer op.  ~80ms is een goed beginpunt.
  // seed wordt niet gebruikt
  // Enkel everr X wordt een vlammetje getoond.  Daartussen is het uit.
 
  timeBezig = currentMillis - timer_rgb_aan[rgbnr];
  // bereken mode (uit, aan, flikker)
  if( timeBezig > (rgbactive[rgbnr].timeon + rgbactive[rgbnr].timeoff) ) {   // aan+uit = lang genoeg uit geweest.  Nu aanzetten
    timer_rgb_aan[rgbnr] = currentMillis;      //reset timers
    timer_rgb_effect[rgbnr] = currentMillis + rgbactive[rgbnr].timeeffect;
    effectrgbbri[rgbnr][0] = random(rgbactive[rgbnr].bri1);
    effectrgbhueidx[rgbnr][0] = 0;
  }
  else  if (timeBezig > rgbactive[rgbnr].timeon) { // einde van aan
    effectrgbbri[rgbnr][0] = 0;
  }
  else  if(currentMillis >  timer_rgb_effect[rgbnr])  {//einde van flikering, begin een nieuwe
    effectrgbhueidx[rgbnr][0] = (effectrgbhueidx[rgbnr][0] + 1) % 4; //we hebben 4 kleuren, doe er eentje bij
    effectrgbbri[rgbnr][0] = random(rgbactive[rgbnr].bri1);
    timer_rgb_effect[rgbnr] = currentMillis + random(rgbactive[rgbnr].timeeffect) ; //reset flikkertimer
  }
  else {
    // gewoon verder doen, laat vlammetje maar branden
  }

// bereken kleur
   switch (effectrgbhueidx[rgbnr][0])
   {
   case 0:
    effectrgbhue[rgbnr][0] = rgbactive[rgbnr].hue1;
    effectrgbsat[rgbnr][0] = rgbactive[rgbnr].sat1;
    break;
   case 1:
    effectrgbhue[rgbnr][0] = rgbactive[rgbnr].hue2;
    effectrgbsat[rgbnr][0] = rgbactive[rgbnr].sat2;
    break;
   case 2:
    effectrgbhue[rgbnr][0] = rgbactive[rgbnr].hue3;
    effectrgbsat[rgbnr][0] = rgbactive[rgbnr].sat3;
    break;
   case 3:
    effectrgbhue[rgbnr][0] = rgbactive[rgbnr].hue4;
    effectrgbsat[rgbnr][0] = rgbactive[rgbnr].sat4;
    break;
   default:
    effectrgbhue[rgbnr][0] = 0;
    effectrgbsat[rgbnr][0] = 0;
    break;
   }

  for (size_t i = rgbactive[rgbnr].startrgb; i <= rgbactive[rgbnr].stoprgb; i++)  {
    // aan of uit zetten?
    if( ( (i - rgbactive[rgbnr].startrgb) % rgbactive[rgbnr].every ) == 0 ) {  // check every
      rgbstrip[i] = CHSV(effectrgbhue[rgbnr][0], effectrgbsat[rgbnr][0], effectrgbbri[rgbnr][0]);
    }
    else {
      rgbstrip[i] = CRGB::Black;
    }
  }
}
