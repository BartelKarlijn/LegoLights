#pragma once
#include <Arduino.h>

// External libraries
// read and save data
#include <Preferences.h>     // om data in eprom op te slaan
#include <SPIFFS.h>        // om het filesysteem van ESP32 te gebruiken
#include <ArduinoJson.h>

// Wifi
#include <WiFi.h>           //
#include <AsyncTCP.h>       // nodig voor de ESPAyncWebserver
#include <ESPAsyncWebServer.h>
#include <ElegantOTA.h>
#include <WebSerial.h>

// Ledstrip
#include <FastLED.h>

// PCA9865 servo/led driver
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Own libraries
// variables
#include "0main/configuration.h"
#include "0main/globalvariables.h"
#include "0main/config_colors.h"
#include "0main/config_commands.h"

// Own subroutines
//   main
#include "0main/setupSerial.h"
#include <PrintAnyFormat.h>
//#include <ESPtools.h>
#include "C:\NonSyncing\Github repository\ESPtools\src\ESPtools.h"
#include "0main/setupLed.h"
#include "0main/setupLedstrip.h"

// commands
#include "commands/cW01wifiShowNetworks.h"
#include "commands/decodeCommand.h"
#include "commands/readcommand.h"
#include "0main/config_validCommands.h"
#include "commands/executeCommand.h"

// Spiffs() integrated file system)
#include "spiffs/fileDefault2Huis.h"
#include "spiffs/fileLoad2Huis.h"
#include "spiffs/fileDefault2Kring.h"
#include "spiffs/fileLoad2Kring.h"
#include "spiffs/fileSaveKring.h"

// fps
#include "0main/show_fps.h"

//ledstrip
#include "ledstrip/listKringen.h"
#include "ledstrip/str_aan.h"
#include "ledstrip/str_chase.h"
#include "ledstrip/str_fire.h"
#include "ledstrip/str_glow.h"
#include "ledstrip/str_party.h"
#include "ledstrip/str_uit.h"
#include "ledstrip/showstrip.h"
#include "ledstrip/loadAnimatie.h"

//sigleled
#include "singleled/led_aan.h"
#include "singleled/led_fire.h"
#include "singleled/led_glow.h"
#include "singleled/led_uit.h"
#include "singleled/showled.h"

//wifi
#include "wifi/on_file.h"            // downloaden of verwijderen
#include "wifi/on_fileUpload.h"
#include "wifi/onOTA.h"
#include "wifi/on_getStrip.h"
#include "wifi/on_getSetStrip.h"
#include "wifi/on_getfileLoad2Kring.h"
#include "wifi/on_getfileDefault2Kring.h"
#include "wifi/on_getfileSaveKring.h"
#include "wifi/on_getlistKringen.h"
#include "wifi/on_wifisave.h"
#include "wifi/setup_AsyncWebserver.h" 
