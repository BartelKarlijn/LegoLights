#include <0main\0include.h>

// =======================================================================================
// Setup
// =======================================================================================
void setup() {
  setupSerial();
  setupLedstrip();        // voornamelijk leds afzetten
  Wifi_get_from_eeprom(); // parameters uit eeprom halen (oa ssid/pw en PID)
  startWifi();
  setupSpiffs();          // van het ESP32 file systeem lezen
  setupLed();
  loadAnimatie();         // ini file, terugvallen naar default
  SetupFinished();
}
void loop() {
  currentMillis = millis();
  show_fps();    // print om de zoveel tijd de fps
  readcommand(); // commando's van de serial poort lezen
  showstrip();   // toon alles van de strip
  FastLED.show();
  
  showled();     // ledjes tonen
}
