#pragma once
void setupRgb() {

  FastLED.addLeds< NEOPIXEL, RGB_PIN >(rgbstrip, RGB_NR_LEDS);  // GRB ordering is assumed

  // set master brightness control
  FastLED.setBrightness(RGB_BRIGHTNESS);
  FastLED.clear();  // clear all pixel data
  FastLED.show();

// Nog geen wifi, dus geen Print
  Print("Rgb: ");
  Print(String(RGB_NR_ITEMS));
  Print(" leds: ");
  Println(RGB_NR_LEDS);

}
