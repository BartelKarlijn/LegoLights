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
#define STR_OLI_0PLAF_STOPLED     0
#define STR_OLI_0PLAF_HUE1       64  //0:red, 32: orange, 64: yellow, 128: aqua, 192: purple, 255:red'
#define STR_OLI_0PLAF_BRIGHT1   128
#define STR_OLI_0PLAF_HUE2        0
#define STR_OLI_0PLAF_BRIGHT2     0
#define STR_OLI_0PLAF_HUE3        0
#define STR_OLI_0PLAF_BRIGHT3     0
#define STR_OLI_0PLAF_HUE4        0
#define STR_OLI_0PLAF_BRIGHT4     0
#define STR_OLI_0PLAF_EVERY       1
#define STR_OLI_0PLAF_TIME1    2000  //(ms) aan: tijd op
#define STR_OLI_0PLAF_TIME2     500  //(ms) aan: tijd uit
#define STR_OLI_0PLAF_TIM_FLICK   0
#define STR_OLI_0PLAF_DIRECTION   false

#define STR_OLI_0TRAP             1
#define STR_OLI_0TRAP_STARTLED    1
#define STR_OLI_0TRAP_STOPLED     1
#define STR_OLI_0TRAP_HUE1       64
#define STR_OLI_0TRAP_BRIGHT1   128
#define STR_OLI_0TRAP_HUE2        0
#define STR_OLI_0TRAP_BRIGHT2     0
#define STR_OLI_0TRAP_HUE3        0
#define STR_OLI_0TRAP_BRIGHT3     0
#define STR_OLI_0TRAP_HUE4        0
#define STR_OLI_0TRAP_BRIGHT4     0
#define STR_OLI_0TRAP_EVERY       1
#define STR_OLI_0TRAP_TIME1    1500  //aan: tijd op
#define STR_OLI_0TRAP_TIME2    1000  //aan: tijd uit
#define STR_OLI_0TRAP_TIM_FLICK   0
#define STR_OLI_0TRAP_DIRECTION   false

//laatste item definieren
#define STR_NR_ITEMS 1+ STR_OLI_0TRAP  //om arrays te definieren
#define STR_NUM_LEDS STR_OLI_0TRAP_STOPLED + 1
