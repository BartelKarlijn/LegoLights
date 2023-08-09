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

  // strip conecteren
  // strip aan/uit

}
