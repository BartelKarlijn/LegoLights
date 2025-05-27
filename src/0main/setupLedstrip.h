#pragma once
void setupLedstrip() {

  FastLED.addLeds< NEOPIXEL, STR_PIN >(rgbstrip, STRIP_NR_LEDS);  // GRB ordering is assumed

  // set master brightness control
  FastLED.setBrightness(STR_BRIGHTNESS);
  FastLED.clear();  // clear all pixel data
  FastLED.show();

// Nog geen wifi, dus geen Print
  Print("Kringen: ");
  Print(String(STRIP_NR_ITEMS));
  Print(" leds: ");
  Println(STRIP_NR_LEDS);

  // kringen initialiseren wordt later gedaan
}
