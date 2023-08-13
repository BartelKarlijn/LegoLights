#pragma once

void led_aan(int kringnr) {
  singleled.setPWM(1, 0, 4095);
}
