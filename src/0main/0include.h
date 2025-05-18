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

// Spiffs() integrated file system)
#include "spiffs/fileHuisLoadSettings.h"
#include "spiffs/fileHuisSaveSettings.h"
#include "spiffs/fileLedLoadSettings.h"
#include "spiffs/fileLedSaveSettings.h"
#include "spiffs/file0ldLoad2Huis.h"
#include "spiffs/fileDefault2Kring.h"
#include "spiffs/fileLoad2Kring.h"
#include "spiffs/fileSaveKring.h"
#include "spiffs/file0ldLedListAnim.h"
#include "spiffs/file0ldListLed.h"
#include "spiffs/file0ldSaveLed.h"
#include "spiffs/file0ldLoadLed.h"
#include "spiffs/file0ldDeleteLed.h"

// commands
#include "commands/cF01fpsShow.h"
#include "commands/cK01kringSetJpg.h"
#include "commands/cK02kringSetName.h"
#include "commands/cK03kringStartStop.h"
#include "commands/cK04kringEvery.h"
#include "commands/cK05kringHue.h"
#include "commands/cK06kringSat.h"
#include "commands/cK07kringBri.h"
#include "commands/cK08kringTonToff.h"
#include "commands/cK09kringEffect.h"
#include "commands/cK10kringSeed.h"
#include "commands/cK20kringSaveSetting.h"
#include "commands/cK21kringLoadSetting.h"
#include "commands/cK22kringDefaultSet.h"
#include "commands/cL02ledSetName.h"
#include "commands/cL07ledSetBrightness.h"
#include "commands/cL08ledSetTimeOnOff.h"
#include "commands/cL09ledSetEffect.h"
#include "commands/cL20ledSaveSetting.h"
#include "commands/cL21ledLoadSetting.h"
#include "commands/cL22ledDeleSetting.h"
#include "commands/cW01wifiShowNetworks.h"
#include "0main/config_validCommands.h"
#include "commands/cC00Help.h"  // Deze moet na de config staan, want toont wat daar staat
#include "commands/decodeCommand.h"
#include "commands/executeCommand.h"
#include "commands/readSerial.h"

//rgb
#include "ledstrip/listKringen.h"
#include "ledstrip/str_aan.h"
#include "ledstrip/str_chase.h"
#include "ledstrip/str_fire.h"
#include "ledstrip/str_glow.h"
#include "ledstrip/str_party.h"
#include "ledstrip/str_uit.h"
#include "ledstrip/showstrip.h"

//sigleled
#include "singleled/led_aan.h"
#include "singleled/led_fire.h"
#include "singleled/led_glow.h"
#include "singleled/led_ramp.h"
#include "singleled/led_rand.h"
#include "singleled/led_uit.h"
#include "singleled/showled.h"
#include "singleled/settingLedApplyAnim.h"
#include "singleled/settingLedDelete.h"
#include "singleled/settingLedListAnim.h"
#include "singleled/settingLedUpdate.h"

// fps & anims
#include "0main/show_fps.h"
#include "0main/loadAnimatie.h"

//wifi
#include "wifi/on_file.h"            // downloaden of verwijderen
#include "wifi/on_fileUpload.h"
#include "wifi/on_getStrip.h"
#include "wifi/on_getLed.h"
#include "wifi/on_getSetStrip.h"
#include "wifi/on_getSetLed.h"
#include "wifi/on_getfileLedListAnim.h"
#include "wifi/on_getfileLoad2Kring.h"
#include "wifi/on_getfileLoad2Led.h"
#include "wifi/on_getfileDefault2Kring.h"
#include "wifi/on_getfileSaveKring.h"
#include "wifi/on_getfileSaveLed.h"
#include "wifi/on_getlistKringen.h"
#include "wifi/on_wifisave.h"
#include "wifi/setup_AsyncWebserver.h" 
