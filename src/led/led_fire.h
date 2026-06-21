#pragma once

void led_fire(uint8_t lednr) {
  unsigned long timeBezig;

  timeBezig  = currentMillis - timer_led_aan[lednr];

  if( timeBezig > (ledactive[lednr].timeon + ledactive[lednr].timeoff) ) {   // lang genoeg uit geweest.  Nu aanzetten
    timer_led_aan[lednr]  = currentMillis; //reset timer
    time_led_eff[lednr]  = random(ledactive[lednr].timeeffect); //reset timer
    effectledbri[lednr] = ledactive[lednr].bri / 3 + random(ledactive[lednr].bri);      //intensiteit

    ledPCA9685.setPWM(lednr, 0, effectledbri[lednr]);
  }
  else  if (timeBezig > ledactive[lednr].timeon) { // lang genoeg aan geweest. Nu uitzetten
    ledPCA9685.setPWM(lednr, 0, 0);
  }
  else if (timeBezig > time_led_eff[lednr] ) { // ander vlammetje
    time_led_eff[lednr]  += random(ledactive[lednr].timeeffect); //Vergroot timer naar eind volgend vlammetje
    effectledbri[lednr]   = ledactive[lednr].bri / 3 + random(ledactive[lednr].bri);      //intensiteit

    ledPCA9685.setPWM(lednr, 0, effectledbri[lednr]);
  }
  else {     //laat nog maar tijdje aan.

  }
}
