void setupLedstrip() {

  FastLED.addLeds<NEOPIXEL, PIN_STRIP>(ledstrip, NUM_LEDS_IN_STRIP);  // GRB ordering is assumed
  // set master brightness control
  FastLED.setBrightness(STRIP_BRIGHTNESS);
  FastLED.clear();  // clear all pixel data

}