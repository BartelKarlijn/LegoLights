#pragma once

void led_uit(uint8_t lednr) {
    ledPCA9685.setPWM(lednr, 0, 0);
}
