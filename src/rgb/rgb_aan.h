#pragma once

void rgb_aan(size_t rgbnr) {
  // Aan/uit zetten van RGB strip
  // We gebruiken 2 kleuren.  kleur1 begint, en komt elke every terug.  Daartussen kleur2.
  // seed geeft aan waar de eerste kleur begint.  Kan positief of negatief zijn.

  bool fl_on;
  unsigned long timeBezig;

  timeBezig = currentMillis - timer_rgb_aan[rgbnr];

  if( timeBezig > (rgbactive[rgbnr].timeon + rgbactive[rgbnr].timeoff) ) {   // lang genoeg uit geweest.  Nu aanzetten
    fl_on = true;
    timer_rgb_aan[rgbnr] = currentMillis; //reset timer
  }
  else  if (timeBezig > rgbactive[rgbnr].timeon) { // lang genoeg aan geweest
    fl_on = false;
  }
  else {     //laat nog maar tijdje aan.
    fl_on = true;
  }

  for (size_t i = rgbactive[rgbnr].startrgb; i <= rgbactive[rgbnr].stoprgb; i++)
  {
    // aan of uit zetten?
    if (fl_on) {
      if( ( (i - rgbactive[rgbnr].startrgb + rgbactive[rgbnr].seed + 30*rgbactive[rgbnr].every) % rgbactive[rgbnr].every ) == 0 ) {  // check every.  Aangezien negatieve waarden kunnen voorkomen, tellen we er 30 x every bij op om zeker positieve waarden te hebben
        rgbstrip[i] = CHSV(rgbactive[rgbnr].hue1, rgbactive[rgbnr].sat1, rgbactive[rgbnr].bri1 );
      }
      else {
        rgbstrip[i] = CHSV(rgbactive[rgbnr].hue2, rgbactive[rgbnr].sat2, rgbactive[rgbnr].bri2 );
      }
    }
    else {
      rgbstrip[i] = CRGB::Black;
    }
  }
}
