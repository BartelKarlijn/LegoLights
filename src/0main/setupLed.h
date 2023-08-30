#pragma once
void setupLed() {
// for the adafruit PCA9685 servo driver
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
  singleled.begin();          //start PCA9685 for diagon Alley
  singleled.setPWMFreq(1600); // This is the maximum PWM frequency and suited to LED's

  // leds initialiseren met default
  for (size_t lednr = 0; lednr < LED_NR_ITEMS; lednr++) {
    ledsingle[lednr] = LED_DEFAULT[lednr];
    singleled.setPWM(lednr, 0, 0);     // alles uitzetten
  }
  Println("Single leds setup done");
}
