#pragma once

void led_aan(int lednr) {
  unsigned long timeBezig;

  timeBezig = currentMillis - timer_led_aan[lednr];

  if( timeBezig > (ledactive[lednr].timeon + ledactive[lednr].timeoff) ) {   // lang genoeg uit geweest.  Nu aanzetten
    ledPCA9685.setPWM(lednr, 0, ledactive[lednr].bri);
    timer_led_aan[lednr] = currentMillis; //reset timer
  }
  else  if (timeBezig > ledactive[lednr].timeon) { // lang genoeg aan geweest
    ledPCA9685.setPWM(lednr, 0, 0);
  }
  else {     //laat nog maar tijdje aan.

  }

}
