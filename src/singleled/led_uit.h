#pragma once

void led_uit(int lednr) {
    singleled.setPWM(lednr, 0, 0);
}
