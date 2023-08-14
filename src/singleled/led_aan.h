#pragma once

void led_aan(int lednr) {
  unsigned long timeBezig;

  timeBezig = currentMillis - timer_led_aan[lednr];

  if( timeBezig > (singled[lednr].timeon + singled[lednr].timeoff) ) {   // lang genoeg uit geweest.  Nu aanzetten
    singleled.setPWM(lednr, 0, singled[lednr].bright);
    timer_led_aan[lednr] = currentMillis; //reset timer
  }
  else  if (timeBezig > singled[lednr].timeon) { // lang genoeg aan geweest
    singleled.setPWM(lednr, 0, 0);
  }
  else {     //laat nog maar tijdje aan.

  }

}
