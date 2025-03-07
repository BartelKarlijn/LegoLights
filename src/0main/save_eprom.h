#pragma once
// Complete project details at https://RandomNerdTutorials.com/esp32-save-data-permanently-preferences/
// The Preferences library in the ESP32 framework provides a way to store and retrieve key-value pairs in non-volatile storage (NVS). 
#include <Preferences.h>
#define NAMESPACE "WIFI"

Preferences pref_eeprom;           // to store & read parameters from eprom

enum WifiParam {
  SSID,
  PWD
};

// Function to get data from EEPROM
String Wifi_get_from_eeprom (WifiParam param) {
  // Open Preferences with WIFI namespace. Each application module, library, etc
  // has to use a namespace name to prevent key name collisions. We will open storage in
  // RW-mode (second parameter has to be false).
  // Note: Namespace name is limited to 15 chars.
  if (!pref_eeprom.begin(NAMESPACE, false)) {
    Serial.println("Failed to open EEPROM");
    return "Error";
}

  // Get the counter value, if the key does not exist, return a default value of 0
  // Note: Key name is limited to 15 chars.
  if (param == SSID) {
    wifi_ssid = pref_eeprom.getString("ssid_eeprom", "");
    Serial.print("Uit eprom uitgelezen waarde voor SSID = ");
    Serial.println(wifi_ssid);
    return wifi_ssid;
} else if (param == PWD) {
    wifi_pwd = pref_eeprom.getString("pwd_eeprom", "");
    Serial.print("Uit eprom uitgelezen waarde voor PWD = ");
    Serial.println("*****");
    return wifi_pwd;
}
  
  // Close Preferences
  pref_eeprom.end();
}


void Wifi_save_to_eeprom (String wifi_ssid, String wifi_pwd) {
  pref_eeprom.putString("ssid_eeprom", wifi_ssid);
  pref_eeprom.putString("pwd_eeprom" , wifi_pwd);

  Println("Wifi data saved");

  delay(1000);
  Println("nog eens uitlezeen");
  String ssid_eeprom = pref_eeprom.getString("ssid_eeprom","");
  Print("Uit eprom uitgelezen waarde voor SSID = ");
  Println(ssid_eeprom);
  String pwd_eeprom = pref_eeprom.getString("pwd_eeprom","");
  Print("Uit eprom uitgelezen waarde voor PWD = ");
  Println(pwd_eeprom);
}
