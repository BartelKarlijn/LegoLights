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
  show_fps();

  str_aan(0);
  str_glow(1);
  str_fire(2);
  str_party(3);
  FastLED.show();
  
}
