#pragma once

void led_fire(int lednr) {
  unsigned long timeBezig;

  timeBezig = currentMillis - timer_led_aan[lednr];

  if( timeBezig > (ledsingle[lednr].timeon + ledsingle[lednr].timeoff) ) {   // lang genoeg uit geweest.  Nu aanzetten
    timer_led_aan[lednr]    = currentMillis; //reset timer
    timer_led_effect[lednr] = currentMillis; //reset timer

    singleled.setPWM(lednr, 0, ledsingle[lednr].bright);
  }
  else  if (timeBezig > ledsingle[lednr].timeon) { // lang genoeg aan geweest
    singleled.setPWM(lednr, 0, 0);
  }
  else if (timeBezig > timer_led_effect[lednr] ) { // ander vlammetje
    flameledbright[lednr]   = random(ledsingle[lednr].bright);
    timer_led_effect[lednr] = random(ledsingle[lednr].timeeffect);
    singleled.setPWM(lednr, 0, flameledbright[lednr]);
  }
  else {     //laat nog maar tijdje aan.

  }

}
