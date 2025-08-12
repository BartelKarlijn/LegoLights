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
#include "0main/setupRgb.h"

// Spiffs(integrated file system)
#include "spiffs/fileHuisLoadSettings.h"
#include "spiffs/fileHuisSaveSettings.h"
#include "spiffs/fileLedLoadSettings.h"
#include "spiffs/fileLedSaveSettings.h"
#include "spiffs/fileRgbLoadSettings.h"
#include "spiffs/fileRgbSaveSettings.h"

//huis
#include "huis/huisValueGet.h"
#include "huis/huisValueSet.h"
#include "huis/huisListAnim.h"

//led
#include "led/led_aan.h"
#include "led/led_fire.h"
#include "led/led_glow.h"
#include "led/led_ramp.h"
#include "led/led_rand.h"
#include "led/led_uit.h"
#include "led/ledValueGet.h"
#include "led/ledValueSet.h"
#include "led/showled.h"
#include "led/ledAnimApply.h"
#include "led/ledAnimSaveMem.h"
#include "led/ledLoadAnim.h"
#include "led/ledListAnim.h"
#

//rgb
#include "rgb/rgb_aan.h"
#include "rgb/rgb_chase.h"
#include "rgb/rgb_fire.h"
#include "rgb/rgb_glow.h"
#include "rgb/rgb_party.h"
#include "rgb/rgb_uit.h"
#include "rgb/rgbValueGet.h"
#include "rgb/rgbValueSet.h"
#include "rgb/showrgb.h"
#include "rgb/rgbAnimApply.h"
#include "rgb/rgbAnimSaveMem.h"
#include "rgb/rgbLoadAnim.h"
#include "rgb/rgbListAnim.h"

// Wifi Actions
#include "wifi/decodeRequestHuis.h"
#include "wifi/decodeRequestLed.h"
#include "wifi/decodeRequestRgb.h"
#include "wifi/on_file.h"            // downloaden of verwijderen
#include "wifi/on_fileUpload.h"
#include "wifi/on_showfirmware.h"   // tonen van de firmware versie
#include "wifi/on_wifisave.h"

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
#include "commands/cL02ledSetName.h"
#include "commands/cL07ledSetBrightness.h"
#include "commands/cL08ledSetTimeOnOff.h"
#include "commands/cL09ledSetEffect.h"
#include "commands/cL20ledSaveSetting.h"
#include "commands/cL21ledLoadSetting.h"
#include "commands/cW01wifiShowNetworks.h"
#include "0main/config_validCommands.h"
#include "commands/cC00Help.h"  // Deze moet na de config staan, want toont wat daar staat
#include "commands/decodeCommand.h"
#include "commands/executeCommand.h"
#include "commands/readSerial.h"

// fps & anims
#include "0main/show_fps.h"
#include "0main/loadAnimatie.h"

//wifi
#include "wifi/setup_AsyncWebserver.h" 
