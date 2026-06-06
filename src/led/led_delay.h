#pragma once

void led_delay(size_t lednr) {
  unsigned long timeBezig;

  timeBezig = currentMillis - timer_led_aan[lednr];

  if( timeBezig > (ledactive[lednr].timeon + ledactive[lednr].timeoff) ) {   // lang genoeg uit geweest.  Nog niet aanzetten, eerst delay uitzitten
    ledPCA9685.setPWM(lednr, 0, 0);
    timer_led_aan[lednr] = currentMillis; //reset timer
  }
  else  if (timeBezig > ledactive[lednr].timeon) { // lang genoeg aan geweest
    ledPCA9685.setPWM(lednr, 0, 0);
  }
  else  if (timeBezig > ledactive[lednr].timeeffect) { //delay uitgezeten
    ledPCA9685.setPWM(lednr, 0, ledactive[lednr].bri);
  }
  else {     //delay uitzitten
    ledPCA9685.setPWM(lednr, 0, 0);
  }
}
