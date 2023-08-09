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

///////////////// movement modes  //////////////////////////////
// Describing how much action is shown when moving from one to another digit
#define MOVEMENT_MIN 0   // as little movement as possible
#define MOVEMENT_MAX 1   // as much movement as possible
#define MOVEMENT_FUN 2   // balanced
#define MOVEMENT_DESC_MIN "minimum"
#define MOVEMENT_DESC_MAX "maximum"
#define MOVEMENT_DESC_FUN "balanced"
#define MOVEMENT_COUNT 3
String movementTbl[MOVEMENT_COUNT] = {MOVEMENT_DESC_MIN, MOVEMENT_DESC_MAX, MOVEMENT_DESC_FUN };
#define RANDOM_OFF 0
#define RANDOM_ON  1
#define RANDOM_DESC_OFF "normal"
#define RANDOM_DESC_ON  "random"
#define RANDOM_DESCCOUNT 2
String randomTbl[RANDOM_DESCCOUNT] = {RANDOM_DESC_OFF, RANDOM_DESC_ON};

///////////////// working modes  //////////////////////////////
#define OPERATION_CLOCK          0       // Regular clock mode
#define OPERATION_CLOCKDEMO      1       // 'Demo' clock by rapidly browsing nrs
#define OPERATION_CHECKFPS       2       // check how many fps we can achieve
#define OPERATION_DIGITSHOW      3       // Test digits one by one (no movement in between)
#define OPERATION_DIGITDANCE     4       // Do movement betwen digits
#define OPERATION_SLAVE          5
#define OPERATION_DESC_CHECKFPS   "CheckPFS"
#define OPERATION_DESC_CLOCK      "Clock"
#define OPERATION_DESC_CLOCKDEMO  "ClockDemo"
#define OPERATION_DESC_DIGITSHOW  "DigitShow"
#define OPERATION_DESC_DIGITDANCE "DigitDance" 
#define OPERATION_DESC_SLAVE      "Slave"
#define OPERATION_DESC_COUNT 6
String operationTbl[OPERATION_DESC_COUNT] = {OPERATION_DESC_CLOCK, OPERATION_DESC_CLOCKDEMO, OPERATION_DESC_CHECKFPS, OPERATION_DESC_DIGITSHOW, OPERATION_DESC_DIGITDANCE, OPERATION_DESC_SLAVE};

///////////////// Commands  //////////////////////////////
// Commmands are fixed lenght of 1
#define COMMAND_CLEARS    1  // Clear screen without.                     Param 0=clear axis, 1=plot axis
#define COMMAND_SHOWDG    3  // Show digit                                Param = digit to show
#define COMMAND_MOVETO    4  // Move to digit                             Param = digit moving to
#define COMMAND_RANDOM    5  // Move to random digit
#define COMMAND_SETMOD    6  // Set in specific mode                      Param = new mode
#define COMMAND_SETROT    7  // Set rotation
#define COMMAND_SETMOV    8  // Set movementmode
#define COMMAND_SETSAV    9  // Save settings
#define CMD_START        '<' // char
#define CMD_STOP         '>' // char
