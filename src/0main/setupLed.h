#pragma once
void setupLed() {
// for the adafruit PCA9685 servo driver
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
  ledPCA9685.begin();          //start PCA9685 for diagon Alley
  ledPCA9685.setPWMFreq(PCA9685_FREQUENCY); // This is the maximum PWM frequency and suited to LED's

  // leds initialiseren met default
  for (uint8_t lednr = 0; lednr < LED_NR_ITEMS; lednr++) {
    ledPCA9685.setPWM(lednr, 0, 0);     // alles uitzetten
  }
  Println("Single leds setup done");
}
