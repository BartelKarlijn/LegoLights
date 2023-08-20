//////////////// OPERATION ///////////////////////
Preferences pref_eeprom;           // to store & read parameters from eprom

//////// Wifi //////////
// Create AsyncWebServer object on port 80
AsyncWebServer webserver(80);
//DNSServer dnsServer;    //Even afgezet want voor eigen AP wellicht niet nodig
String wifi_ssid ;
String wifi_pwd  ;
String wifi_scan;         //Lijst met scan van wifi netwerken
String listFiles(bool ishtml = false);

bool   flagWifiOn = false;

// knoppen
const char* PARAM_output = "output";   // voor de asyncwebserver

const char* oms_mode = "Operation Mode";
const uint16_t   id_Modeup = 121;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Modedo = 122; 

const char* oms_namePtr = "Name mstr/slave";
const uint16_t   id_namePtrup = 131;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_namePtrdo = 132; 

const char* oms_waitDelay = "Delay between steps";
const uint16_t   id_waitDelayup = 141;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_waitDelaydo = 142; 

const char* oms_mvmt = "Movement Mode";
const uint16_t   id_Mvmtup = 151;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Mvmtdo = 152; 

const char* oms_rand = "Random Mode";
const uint16_t   id_Randup = 161;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Randdo = 162; 

const char* oms_Rot = "Rotation sc";
const uint16_t   id_Rotup = 201;            // knop ID, moet uniek zijn, zie html_processor
const uint16_t   id_Rotdo = 202; 

const char* oms_TimeSave = "Set time HH MM";
const char* PARAM_HH    = "hh";             // parameter for asyncwebserver
const char* PARAM_MM    = "mm";             // parameter for asyncwebserver

const char* oms_WifiSave = "SSID / Password";
const char* PARAM_ssid   = "ssid";     // voor de asyncwebserver
const char* PARAM_pwd    = "pwd" ;     // voor de asyncwebserver

const char* oms_SaveConfig = "Save Config";
const uint16_t   id_SaveConfig = 22;

const char* oms_Restart = "Restart";
const uint16_t   id_Restart = 23;

//////// PCA9685 led servodriver //////////
//set the board address, PCA9685 come as 0x40 by default
// via  singleled/scanI2C gecontroleerd: 0x40 is idd het nr
Adafruit_PWMServoDriver singleled = Adafruit_PWMServoDriver(0x40, Wire);

//////// Timing //////////
unsigned long currentMillis;
unsigned long fpsMillis;
unsigned long cntfps = 1;  // we willen geen 0 om eventuele delingen door 0 te vermijden
