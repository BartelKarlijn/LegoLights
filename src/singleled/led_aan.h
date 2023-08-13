#pragma once

void led_aan(int lednr) {
  singleled.setPWM(lednr, 0, 4096);
  delay(2000);
  singleled.setPWM(lednr, 0, 4096);
  delay(2000);
}
