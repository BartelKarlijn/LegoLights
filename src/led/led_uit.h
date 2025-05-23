#pragma once

void led_uit(int lednr) {
    ledPCA9685.setPWM(lednr, 0, 0);
}
