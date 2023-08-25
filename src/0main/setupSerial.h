#pragma once
void setupSerial () {
  Serial.begin(SERIALSPEED);
  delay(100);
  // No wifi yet, so using Serial.print
  Serial.println("Starting ESP32");
  Serial.print("Setup running on core: ");
  Serial.println(xPortGetCoreID());

  Serial.print("Commitpoint ");
  Serial.println(String(AUTO_COMMITPT) );
  Serial.print("Compilation date ");
  Serial.println( String(__DATE__) + " "  + String(__TIME__) );

  delay(100);
}

void SetupFinished() {
  Serial.println("All started up correctly");
}