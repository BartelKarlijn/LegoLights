#include <main\include.h>

// =======================================================================================
// Setup
// =======================================================================================
void setup() {
  setupSerial();
  delay(1000);
  get_datafrom_eeprom (); // parameters uit eeprom halen (oa ssid/pw en PID)

  SetupFinished();
}
void loop() {
  // put your main code here, to run repeatedly:
}
