#pragma once
// Configuration file

///////////////// Serial  ///////////////////////////
// One, both or none of the Print options below can be used
#define PRINTWEBSERIAL   // follow print statements via web Serial.  Page adress: ipadres/webserial
#define PRINTSERIAL      // follow prints via serial connection
#define SERIALSPEED 115200

///////////////// Pins  //////////////////////////////
// already used in user_setup.h, and platformio.ini
// Default pinmapping for SPI = MOSI gpio23, MISO gpio19, CLK gpio18, CS gpio5 (but this we're doing ourselves)

///////////////// wifi  //////////////////////////////
// names below are used as AccessPoint name and calls from master
#define NAME_ACCESSPOINT "DiagonAlley"

///////////////// ledstrip  //////////////////////////////
// gegevens over de ledstrip
#define STR_PIN 12
#define STR_BRIGHTNESS 50 

#define STR_OLI_0PLAF             0
#define STR_OLI_0PLAF_STARTLED    0
#define STR_OLI_0PLAF_STOPLED    10
#define STR_OLI_0PLAF_COLOR1 CRGB::Red
#define STR_OLI_0PLAF_COLOR2 CRGB::Black
#define STR_OLI_0PLAF_COLOR3 CRGB::Black
#define STR_OLI_0PLAF_COLOR4 CRGB::Black
#define STR_OLI_0PLAF_FADE1      150
#define STR_OLI_0PLAF_FADE2       0
#define STR_OLI_0PLAF_FADE3       0
#define STR_OLI_0PLAF_FADE4       0
#define STR_OLI_0PLAF_EVERY       5
#define STR_OLI_0PLAF_TIME1    2000  //(ms) aan: tijd op
#define STR_OLI_0PLAF_TIME2     500  // (ms) aan: tijd uit
#define STR_OLI_0PLAF_TIM_FLICK   0
#define STR_OLI_0PLAF_DIRECTION   false

#define STR_OLI_0TRAP             1
#define STR_OLI_0TRAP_STARTLED   11
#define STR_OLI_0TRAP_STOPLED    14
#define STR_OLI_0TRAP_COLOR1 CRGB::Red
#define STR_OLI_0TRAP_COLOR2 CRGB::Black
#define STR_OLI_0TRAP_COLOR3 CRGB::Black
#define STR_OLI_0TRAP_COLOR4 CRGB::Black
#define STR_OLI_0TRAP_FADE1       0
#define STR_OLI_0TRAP_FADE2       0
#define STR_OLI_0TRAP_FADE3       0
#define STR_OLI_0TRAP_FADE4       0
#define STR_OLI_0TRAP_EVERY       3
#define STR_OLI_0TRAP_TIME1    1500  //aan: tijd op
#define STR_OLI_0TRAP_TIME2    1000  //aan: tijd uit
#define STR_OLI_0TRAP_TIM_FLICK   0
#define STR_OLI_0TRAP_DIRECTION   false

//laatste item definieren
#define STR_NR_ITEMS 1+ STR_OLI_0TRAP  //om arrays te definieren
#define STR_NUM_LEDS STR_OLI_0TRAP_STOPLED + 1
