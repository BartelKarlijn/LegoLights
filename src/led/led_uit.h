#pragma once

void led_uit(size_t lednr) {
    ledPCA9685.setPWM(lednr, 0, 0);
}
