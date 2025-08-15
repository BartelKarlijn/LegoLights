#include <0main\0include.h>

// =======================================================================================
// Setup
// =======================================================================================
void setup() {
  setupSerial();
  delay(100);
  setupRgb();        // voornamelijk leds afzetten
  setupLed();
  startWifi();
  setup_AsyncWebserver();
  setupSpiffs();          // van het ESP32 file systeem lezen
  fileHuisLoadSettings(); // huisSettings inlezen
  fileLedLoadSettings(); // ledsettings inlezen
  fileRgbLoadSettings(); // rgbsettings inlezen
  ledLoadAnim();         // led animatie toepassen
  rgbLoadAnim();         // rgb animatie toepassen
  SetupFinished();
}
void loop() {
  currentMillis = millis();
  show_fps();    // print om de zoveel tijd de fps
  readSerial(); // commando's van de serial poort lezen
  showled();     // ledjes tonen
  showrgb();   // toon alles van de strip  
}
