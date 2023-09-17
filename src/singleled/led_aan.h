#pragma once

void led_aan(int lednr) {
  unsigned long timeBezig;

  timeBezig = currentMillis - timer_led_aan[lednr];

  if( timeBezig > (ledsingle[lednr].timeon + ledsingle[lednr].timeoff) ) {   // lang genoeg uit geweest.  Nu aanzetten
    singleled.setPWM(lednr, 0, ledsingle[lednr].bri);
    timer_led_aan[lednr] = currentMillis; //reset timer
  }
  else  if (timeBezig > ledsingle[lednr].timeon) { // lang genoeg aan geweest
    singleled.setPWM(lednr, 0, 0);
  }
  else {     //laat nog maar tijdje aan.

  }

}
