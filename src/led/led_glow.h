#pragma once

void led_glow(size_t lednr) {
  unsigned long timeBezig;
  unsigned long timeGlowBegin;
  uint8_t bri_glow;

  timeBezig  = currentMillis - timer_led_aan[lednr];
  timeGlowBegin = timer_led_aan[lednr] - ledactive[lednr].timeeffect;

  if( timeBezig > (ledactive[lednr].timeon + ledactive[lednr].timeoff) ) {   // lang genoeg uit geweest.  Nu aanzetten
    timer_led_aan[lednr]  = currentMillis; //reset timer
    time_led_eff[lednr]   = currentMillis + ledactive[lednr].timeeffect;  //up + down glow
    ledPCA9685.setPWM(lednr, 0, 0);         //glow begint aan 0
  }
  else  if (timeBezig > ledactive[lednr].timeon) { // lang genoeg aan geweest. Nu uitzetten
    ledPCA9685.setPWM(lednr, 0, 0);
  }
  else if (timeBezig > time_led_eff[lednr] ) { // nieuwe glow
    timer_led_aan[lednr]  = currentMillis; //reset timer
    time_led_eff[lednr]   = currentMillis + ledactive[lednr].timeeffect;  //up + down glow
    ledPCA9685.setPWM(lednr, 0, 0);         //glow begint aan 0
  }
  else if (timeBezig > (timeGlowBegin + ledactive[lednr].timeeffect / 2 ) ) { // we zijn in de down fase
    bri_glow = map(timeBezig,  timeGlowBegin + ledactive[lednr].timeeffect / 2, timeGlowBegin + ledactive[lednr].timeeffect, ledactive[lednr].bri, 0);
    ledPCA9685.setPWM(lednr, 0, bri_glow);
  }
  else  { // we zijn in de up fase
    bri_glow = map(timeBezig,  timeGlowBegin, timeGlowBegin + ledactive[lednr].timeeffect / 2, 0, ledactive[lednr].bri);
    ledPCA9685.setPWM(lednr, 0, bri_glow);
  }
}
