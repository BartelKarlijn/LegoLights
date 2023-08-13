#pragma once

void showstrip() {
  for (size_t i = 0; i < STRIP_NR_ITEMS; i++) {
    switch (kring[i].effect)
    {
    case EFFSTR_AAN:
        str_aan(i);
        break;
    case EFFSTR_CHASE:
        str_chase(i);
        break;
    case EFFSTR_FIRE:
        str_fire(i);
        break;
    case EFFSTR_GLOW:
        str_glow(i);
        break;
    case EFFSTR_PARTY:
        str_party(i);
        break;
    case EFFSTR_UIT:
        str_uit(i);
        break;
    default:
        break;
    }
  }
}