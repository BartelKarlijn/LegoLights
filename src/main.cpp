#include <0main\0include.h>

// =======================================================================================
// Setup
// =======================================================================================
void setup() {
  setupSerial();
  delay(100);
  setupRgb();        // voornamelijk leds afzetten
  setupLed();
  setupSpiffs();          // van het ESP32 file systeem lezen
  delay(2000); 
  fileHuisLoadSettings(); // huisSettings inlezen, oa MAC adres.
  startWifi(huisSetting.newMACadress); // wifi starten, en eventueel MAC adres aanpassen
  setup_AsyncWebserver();
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
