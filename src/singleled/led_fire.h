#pragma once

void led_fire(int lednr) {
  unsigned long timeBezig;

  timeBezig  = currentMillis - timer_led_aan[lednr];

  if( timeBezig > (ledsingle[lednr].timeon + ledsingle[lednr].timeoff) ) {   // lang genoeg uit geweest.  Nu aanzetten
    timer_led_aan[lednr]  = currentMillis; //reset timer
    time_led_eff[lednr]  = random(ledsingle[lednr].timeeffect); //reset timer
    effectledbright[lednr] = random(ledsingle[lednr].bright);      //intensiteit

    singleled.setPWM(lednr, 0, effectledbright[lednr]);
  }
  else  if (timeBezig > ledsingle[lednr].timeon) { // lang genoeg aan geweest. Nu uitzetten
    singleled.setPWM(lednr, 0, 0);
  }
  else if (timeBezig > time_led_eff[lednr] ) { // ander vlammetje
    time_led_eff[lednr]  += random(ledsingle[lednr].timeeffect); //Vergroot timer naar eind volgend vlammetje
    effectledbright[lednr]   = random(ledsingle[lednr].bright);      //intensiteit
    singleled.setPWM(lednr, 0, effectledbright[lednr]);
  }
  else {     //laat nog maar tijdje aan.

  }
}
