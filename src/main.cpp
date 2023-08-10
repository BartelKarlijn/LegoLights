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
  currentMillis = millis();
  
  // strip aan/uit
  Println("OLI_PLAF");
  str_aan(STR_OLI_0PLAF);
  str_aan(STR_OLI_0TRAP);
  FastLED.show();
  delay(1500);
  
  Println("OLI_TRAP");
  str_uit(STR_OLI_0PLAF);
  str_uit(STR_OLI_0TRAP);
  FastLED.show();
  delay(1000);
}
