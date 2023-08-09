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
#define PIN_STRIP 13
#define STRIP_BRIGHTNESS 150

#define NUM_LEDS_IN_STRIP 32
