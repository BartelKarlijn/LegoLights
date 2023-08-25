#include <0main\include.h>

// =======================================================================================
// Setup
// =======================================================================================
void setup() {
  setupSerial();
  setupLedstrip();        // voornamelijk leds afzetten
  get_datafrom_eeprom (); // parameters uit eeprom halen (oa ssid/pw en PID)
  startWifi();
  setupSpiffs();          // van het ESP32 file systeem lezen
  setupLed();
  SetupFinished();
}
void loop() {
  currentMillis = millis();
  show_fps();    // print om de zoveel tijd de fps
  showstrip();   // toon alles van de strip
  FastLED.show();
  
  showled();     // ledjes tonen
}
