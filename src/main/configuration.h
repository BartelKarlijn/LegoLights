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
#define STR_OLI_0PLAF_STOPLED     2
#define STR_OLI_0PLAF_COLOR1 CRGB::Beige
#define STR_OLI_0PLAF_COLOR2 CRGB::Black
#define STR_OLI_0PLAF_COLOR3 CRGB::Black
#define STR_OLI_0PLAF_COLOR4 CRGB::Black
#define STR_OLI_0PLAF_FADE1      20
#define STR_OLI_0PLAF_FADE2       0
#define STR_OLI_0PLAF_FADE3       0
#define STR_OLI_0PLAF_FADE4       0
#define STR_OLI_0PLAF_EVERY       1
#define STR_OLI_0PLAF_TIM_CHANG   0
#define STR_OLI_0PLAF_TIM_FLICK   0
#define STR_OLI_0PLAF_TIM_COOLD   0
#define STR_OLI_0PLAF_DIRECTION   false

#define STR_OLI_0TRAP          1
#define STR_OLI_0TRAP_STARTLED 3
#define STR_OLI_0TRAP_STOPLED  4
#define STR_OLI_0TRAP_COLOR1 CRGB::Blue
#define STR_OLI_0TRAP_COLOR2 CRGB::Black
#define STR_OLI_0TRAP_COLOR3 CRGB::Black
#define STR_OLI_0TRAP_COLOR4 CRGB::Black
#define STR_OLI_0TRAP_FADE1    0
#define STR_OLI_0TRAP_FADE2       0
#define STR_OLI_0TRAP_FADE3       0
#define STR_OLI_0TRAP_FADE4       0
#define STR_OLI_0TRAP_EVERY       1
#define STR_OLI_0TRAP_TIM_CHANG   0
#define STR_OLI_0TRAP_TIM_FLICK   0
#define STR_OLI_0TRAP_TIM_COOLD   0
#define STR_OLI_0TRAP_DIRECTION   false

//laatste item definieren
#define STR_NR_ITEMS STR_OLI_0TRAP
#define STR_NUM_LEDS STR_OLI_0TRAP_STOPLED + 1
