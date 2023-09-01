#pragma once

void led_fire(int lednr) {
  unsigned long timeBezig;
  unsigned long timeEffect;

  timeBezig  = currentMillis - timer_led_aan[lednr];
  timeEffect = currentMillis - timer_led_eff[lednr];

  if( timeBezig > (ledsingle[lednr].timeon + ledsingle[lednr].timeoff) ) {   // lang genoeg uit geweest.  Nu aanzetten
    timer_led_aan[lednr] = currentMillis; //reset timer
    timer_led_eff[lednr] = currentMillis; //reset timer

    singleled.setPWM(lednr, 0, flameledbright[lednr]);
    if(lednr = 1) {Println("a"); delay(200); };
  }
  else  if (timeBezig > ledsingle[lednr].timeon) { // lang genoeg aan geweest. Nu uitzetten
    singleled.setPWM(lednr, 0, 0);
    if(lednr = 1) {Println("u"); delay(200); };
  }
  else if (timeEffect > fire_time[lednr] ) { // ander vlammetje
    timer_led_eff[lednr] = currentMillis;
    fire_time[lednr]        = random(ledsingle[lednr].timeeffect); //vlamtijd
    flameledbright[lednr]   = random(ledsingle[lednr].bright);      //intensiteit
    singleled.setPWM(lednr, 0, flameledbright[lednr]);
    if(lednr = 1) {    Println("n" ); delay(200); };
  }
  else {     //laat nog maar tijdje aan.

  }
}
