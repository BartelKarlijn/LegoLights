#pragma once
void setupLedstrip() {

  FastLED.addLeds< NEOPIXEL, STR_PIN >(ledstrip, STR_NUM_LEDS);  // GRB ordering is assumed

  // set master brightness control
  FastLED.setBrightness(STR_BRIGHTNESS);
  FastLED.clear();  // clear all pixel data
  FastLED.show();
}