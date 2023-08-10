#pragma once
#include <Arduino.h>

// External libraries
// read and save dta
#include <Preferences.h>   // om op ESP32 eeprom te kunnen lezen en schrijven

// Wifi
#include <WiFi.h>           //
#include <AsyncTCP.h>       // nodig voor de ESPAyncWebserver
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>
#include <WebSerial.h>

// Ledstrip
#include <FastLED.h>

// Own libraries
// variables
#include <main/configuration.h>
#include <main/globalvariables.h>

// Own subroutines
//   main
#include <main/setupSerial.h>
#include <main/print.h>
#include <main/save_eprom.h>
#include <main/setupLedstrip.h>

//wifi
#include <wifi/html_buttonSimple.h>  // routine to create simpel pushbutton
#include <wifi/html_buttonUpDown.h>  // routine to change parameter up or down
#include <wifi/html_buttonLink.h>    // routine to create button with a link
#include <wifi/html_doubleInput.h>   // 2 input fields + submit button
#include <wifi/html_sendPage.h>      // send the (config) html string
#include <wifi/html_processor.h>     // replaces placeholder in sendPage
#include <wifi/buttonChange.h>       // actions happening if you ckick a button
#include <wifi/setup_AsyncWebserver.h> 
#include <wifi/setup_ConnectKnownWifi.h>
#include <wifi/setup_CreateAccessPoint.h>
#include <wifi/startWifi.h>

//ledstrip
#include <ledstrip/str_aan.h>
#include <ledstrip/str_glow.h>
#include <ledstrip/str_uit.h>
