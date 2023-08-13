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
  show_fps();    // print om de zoveel tijd de fps
  showstrip();   // toon alles van de strip
  FastLED.show();
  
}
