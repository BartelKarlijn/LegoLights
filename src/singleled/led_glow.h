#pragma once

void led_glow(int lednr) {
  unsigned long timeBezig;
  unsigned long timeGlowBegin;
  uint8_t brightn_glow;

  timeBezig  = currentMillis - timer_led_aan[lednr];
  timeGlowBegin = timer_led_aan[lednr] - ledsingle[lednr].timeeffect;

  if( timeBezig > (ledsingle[lednr].timeon + ledsingle[lednr].timeoff) ) {   // lang genoeg uit geweest.  Nu aanzetten
    timer_led_aan[lednr]  = currentMillis; //reset timer
    time_led_eff[lednr]   = currentMillis + ledsingle[lednr].timeeffect;  //up + down glow
    singleled.setPWM(lednr, 0, 0);         //glow begint aan 0
  }
  else  if (timeBezig > ledsingle[lednr].timeon) { // lang genoeg aan geweest. Nu uitzetten
    singleled.setPWM(lednr, 0, 0);
  }
  else if (timeBezig > time_led_eff[lednr] ) { // nieuwe glow
    timer_led_aan[lednr]  = currentMillis; //reset timer
    time_led_eff[lednr]   = currentMillis + ledsingle[lednr].timeeffect;  //up + down glow
    singleled.setPWM(lednr, 0, 0);         //glow begint aan 0
  }
  else if (timeBezig > (timeGlowBegin + ledsingle[lednr].timeeffect / 2 ) ) { // we zijn in de down fase
    brightn_glow = map(timeBezig,  timeGlowBegin + ledsingle[lednr].timeeffect / 2, timeGlowBegin + ledsingle[lednr].timeeffect, ledsingle[lednr].bright, 0);
    singleled.setPWM(lednr, 0, brightn_glow);
  }
  else  { // we zijn in de up fase
    brightn_glow = map(timeBezig,  timeGlowBegin, timeGlowBegin + ledsingle[lednr].timeeffect / 2, 0, ledsingle[lednr].bright);
    singleled.setPWM(lednr, 0, brightn_glow);
  }
}
