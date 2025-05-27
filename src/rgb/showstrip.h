#pragma once

void showstrip() {
  for (size_t i = 0; i < STRIP_NR_ITEMS; i++) {
    switch (kring[i].effect)
    {
    case EFFRGB_AAN:
        str_aan(i);
        break;
    case EFFRGB_CHASE:
        str_chase(i);
        break;
    case EFFRGB_FIRE:
        str_fire(i);
        break;
    case EFFRGB_GLOW:
        str_glow(i);
        break;
    case EFFRGB_PARTY:
        str_party(i);
        break;
    case EFFRGB_UIT:
        str_uit(i);
        break;
    default:
        break;
    }
  }
}