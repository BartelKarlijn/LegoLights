#pragma once
#include <Arduino.h>

// External libraries
// read and save data
#include <Preferences.h>   // om op ESP32 eeprom te kunnen lezen en schrijven
#include <SPIFFS.h>        // om het filesysteem van ESP32 te gebruiken
#include <ArduinoJson.h>

// Wifi
#include <WiFi.h>           //
#include <AsyncTCP.h>       // nodig voor de ESPAyncWebserver
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>
#include <WebSerial.h>

// Ledstrip
#include <FastLED.h>

// PCA9865 servo/led driver
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Own libraries
// variables
#include <main/configuration.h>
#include <main/globalvariables.h>
#include <main/config_colors.h>

// Own subroutines
//   main
#include <main/setupSerial.h>
#include <main/print.h>
#include <main/save_eprom.h>
#include <main/setupLed.h>
#include <main/setupLedstrip.h>

// Spiffs() integrated file system)
#include <spiffs/humanReadableSize.h>
#include <spiffs/listFiles.h>
#include <spiffs/listStorage.h>
#include <spiffs/setupSpiffs.h>
#include <spiffs/writeFile.h>
#include <spiffs/readFile.h>
#include <spiffs/loadkring.h>
#include <spiffs/savekring.h>

// fps
#include <main/show_fps.h>

//ledstrip
#include <ledstrip/listKringen.h>
#include <ledstrip/str_aan.h>
#include <ledstrip/str_chase.h>
#include <ledstrip/str_fire.h>
#include <ledstrip/str_glow.h>
#include <ledstrip/str_party.h>
#include <ledstrip/str_uit.h>
#include <ledstrip/showstrip.h>

//sigleled
#include <singleled/scanI2C.h>
#include <singleled/led_aan.h>
#include <singleled/showled.h>

//wifi
//#include <wifi/html_buttonSimple.h>  // routine to create simpel pushbutton
//#include <wifi/html_buttonUpDown.h>  // routine to change parameter up or down
//#include <wifi/html_buttonLink.h>    // routine to create button with a link
//#include <wifi/html_doubleInput.h>   // 2 input fields + submit button
//#include <wifi/html_sendPage.h>      // send the (config) html string
//#include <wifi/html_processor.h>     // replaces placeholder in sendPage
//#include <wifi/buttonChange.h>       // actions happening if you ckick a button
#include <wifi/on_file.h>            // downloaden of verwijderen
#include <wifi/on_fileUpload.h>
#include <wifi/on_getStrip.h>
#include <wifi/on_getSetStrip.h>
#include <wifi/on_getLoadStrip.h>
#include <wifi/on_getSaveStrip.h>
#include <wifi/on_wifisave.h>
#include <wifi/setup_AsyncWebserver.h> 
#include <wifi/setup_ConnectKnownWifi.h>
#include <wifi/setup_CreateAccessPoint.h>
#include <wifi/startWifi.h>
#include <wifi/scanWifiNetworks.h>
