#include <main\include.h>

// =======================================================================================
// Setup
// =======================================================================================
void setup() {
  setupSerial();
  get_datafrom_eeprom (); // parameters uit eeprom halen (oa ssid/pw en PID)
  startWifi();

  SetupFinished();
}
void loop() {
  // put your main code here, to run repeatedly:
}
