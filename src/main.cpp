#include <main\include.h>

// =======================================================================================
// Setup
// =======================================================================================
void setup() {
  setupSerial();
  setupLedstrip();
  get_datafrom_eeprom (); // parameters uit eeprom halen (oa ssid/pw en PID)
  startWifi();

  SetupFinished();
}
void loop() {
  currentMillis = millis();

  // strip aan/uit
  str_aan(STR_OLI_0PLAF);
  str_glow(STR_OLI_0TRAP);
  str_fire(STR_OLI_1PLAF);
  str_party(STR_SCR_0PLAF);
  FastLED.show();
  
}
