#include <main\include.h>

// =======================================================================================
// Setup
// =======================================================================================
void setup() {
  setupSerial();
  get_datafrom_eeprom (); // parameters uit eeprom halen (oa ssid/pw en PID)
  startWifi();
  setupLedstrip();

  SetupFinished();
}
void loop() {
  // put your main code here, to run repeatedly:

  // strip aan/uit
  ledstrip[0] = CRGB::Blue;
  ledstrip[1] = CRGB::Black;
  FastLED.show();
  delay(500);

  ledstrip[0] = CRGB::Black;
  ledstrip[1] = CRGB::Red;
  FastLED.show();
  delay(500);

  ledstrip[0] = CRGB::Beige;
  ledstrip[1] = CRGB::Black;
  FastLED.show();
  delay(500);

  ledstrip[0] = CRGB::Black;
  ledstrip[1] = CRGB::DeepPink;
  FastLED.show();
  delay(500);

}
