#pragma once
void setupLedstrip() {

  FastLED.addLeds< NEOPIXEL, STR_PIN >(ledstrip, STRIP_NR_LEDS);  // GRB ordering is assumed

  // set master brightness control
  FastLED.setBrightness(STR_BRIGHTNESS);
  FastLED.clear();  // clear all pixel data
  FastLED.show();

// Nog geen wifi, dus geen Print
  Serial.print("Kringen: ");
  Serial.print(String(STRIP_NR_ITEMS));
  Serial.print(" leds: ");
  Serial.println(STRIP_NR_LEDS);

  // kringen initialiseren met default
  for (size_t i = 0; i < STRIP_NR_ITEMS; i++) {
    kring[i] = STR_DEFAULT[i];
  }
}
