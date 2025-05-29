#include <0main\0include.h>

// =======================================================================================
// Setup
// =======================================================================================
void setup() {
  setupSerial();
  delay(100);
  setupRgb();        // voornamelijk leds afzetten
  startWifi();
  setup_AsyncWebserver();
  setupSpiffs();          // van het ESP32 file systeem lezen
  setupLed();
  fileHuisLoadSettings(); // huisSettings inlezen
  fileLedLoadSettings(); // ledsettings inlezen
  ledLoadAnim();         // led animatie toepassen
  //loadAnimatie();         // ini file, terugvallen naar default
  SetupFinished();
}
void loop() {
  currentMillis = millis();
  show_fps();    // print om de zoveel tijd de fps
  readSerial(); // commando's van de serial poort lezen
  showled();     // ledjes tonen
  showrgb();   // toon alles van de strip  
}
