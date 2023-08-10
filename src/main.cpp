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
  Println("vast rondje");
  ledstrip[0] = CRGB::Red;
  ledstrip[1] = CRGB::Black;
  FastLED.show();
  delay(500);

  ledstrip[0] = CRGB::Black;
  ledstrip[1] = CRGB::Red;
  FastLED.show();
  delay(500);

  ledstrip[0] = CRGB::DeepPink;
  ledstrip[1] = CRGB::Black;
  FastLED.show();
  delay(500);

  ledstrip[0] = CRGB::Black;
  ledstrip[1] = CRGB::DeepPink;
  FastLED.show();
  delay(500);

  Println("OLI_PLAF");
  aan(STR_OLI_0PLAF);
  uit(STR_OLI_0TRAP);
  FastLED.show();
  delay(1500);
  
  Println("OLI_TRAP");
  uit(STR_OLI_0PLAF);
  aan(STR_OLI_0TRAP);
  FastLED.show();
  delay(1500);
}
