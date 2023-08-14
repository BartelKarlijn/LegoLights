#pragma once

void showled() {
  for (size_t i = 0; i < LED_NR_ITEMS; i++) {
    switch (singled[i].effect)
    {
    case EFFLED_AAN:
        led_aan(i);
        break;
    case EFFLED_FIRE:
//        led_chase(i);
        break;
    case EFFLED_GLOW:
//        led_glow(i);
        break;
    case EFFLED_UIT:
//        led_uit(i);
        break;
    default:
        break;
    }
  }
}