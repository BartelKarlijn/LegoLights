#pragma once

void showled() {
  for (uint8_t i = 0; i < LED_NR_ITEMS; i++) {
    switch (ledactive[i].effect)
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
    case EFFLED_RAMP:
        led_ramp(i);
        break;
    case EFFLED_RAND:
        led_rand(i);
        break;
    case EFFLED_UIT:
        led_uit(i);
        break;
    case EFFLED_DELAY:
        led_delay(i);
        break;
    default:
        break;
    }
  }
}