#pragma once

void led_rand(uint8_t lednr) {
  // Ramping up for timeEffect
  // Keeping on for timeOn
  // Ramping down for timeEffect
  unsigned long timeBezig;
  unsigned long timeEffect;
  uint8_t bri_glow;

  if( currentMillis >= time_fase_end[lednr] ) {   // naar de volgende fase
    fase[lednr]++;
    time_fase_beg[lednr] = currentMillis;
    switch (fase[lednr]){
      case 1:  //up fase
        time_fase_end[lednr] = currentMillis + ledactive[lednr].timeeffect;
        break;        
      case 2:  //on fase
        time_fase_end[lednr] = currentMillis + random(ledactive[lednr].timeon/2, ledactive[lednr].timeon * 2);
        break;        
      case 3:  //donw fase
        time_fase_end[lednr] = currentMillis + ledactive[lednr].timeeffect;
        break;        
      case 4:  //off fase
        time_fase_end[lednr] = currentMillis + ledactive[lednr].timeoff;
        break;        
      default: //5 door ophoging of iets anders: gewoon zelfde als fase1
        time_fase_end[lednr] = currentMillis + ledactive[lednr].timeeffect;
        fase[lednr] = 0;
        break;
    }
  }

  timeBezig  = currentMillis - time_fase_beg[lednr];
  timeEffect = time_fase_end[lednr] - time_fase_beg[lednr];
  switch (fase[lednr])
  {
  case 1: // up
    bri_glow = map_brightness(timeBezig, 0,  timeEffect, 0, ledactive[lednr].bri);
    break;
  case 2: // on
    bri_glow = ledactive[lednr].bri;
    break;
  case 3: // down
    bri_glow = map_brightness(timeBezig, 0, timeEffect, ledactive[lednr].bri, 0);
    break;
  case 4: // off
    bri_glow = 0;
    break;
  default:
    bri_glow = 0;
    break;
  }
  ledPCA9685.setPWM(lednr, 0, bri_glow);
}