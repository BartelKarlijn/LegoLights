#pragma once
void setupLed() {
// for the adafruit PCA9685 servo driver
  Wire.begin();
  singleled.begin();          //start PCA9685 for diagon Alley
  singleled.setPWMFreq(1600); // This is the maximum PWM frequency and suited to LED's
}
