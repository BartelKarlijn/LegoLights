#pragma once

void showrgb() {
  for (uint8_t i = 0; i < RGB_NR_ITEMS; i++) {
    switch (rgbactive[i].effect)
    {
    case EFFRGB_AAN:
        rgb_aan(i);
        break;
    case EFFRGB_CHASE:
        rgb_chase(i);
        break;
    case EFFRGB_FIRE:
        rgb_fire(i);
        break;
    case EFFRGB_GLOW:
        rgb_glow(i);
        break;
    case EFFRGB_PARTY:
        rgb_party(i);
        break;
    case EFFRGB_UIT:
        rgb_uit(i);
        break;
    default:
        break;
    }
  }
  FastLED.show();
}