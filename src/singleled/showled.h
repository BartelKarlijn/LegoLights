#pragma once

void showled() {
  for (size_t i = 0; i < LED_NR_ITEMS; i++) {
    switch (ledsingle[i].effect)
    {
    case EFFLED_AAN:
        led_aan(i);
        break;
    case EFFLED_FIRE:
        led_fire(i);
        break;
    case EFFLED_GLOW:
        led_glow(i);
        break;
    case EFFLED_UIT:
        led_uit(i);
        break;
    default:
        break;
    }
  }
}