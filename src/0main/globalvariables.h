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
const char* PARAM_ssid   = "ssid";     // voor de asyncwebserver
const char* PARAM_pwd    = "pwd" ;     // voor de asyncwebserver

//////// PCA9685 led servodriver //////////
//set the board address, PCA9685 come as 0x40 by default
// via  singleled/scanI2C gecontroleerd: 0x40 is idd het nr
Adafruit_PWMServoDriver singleled = Adafruit_PWMServoDriver(0x40, Wire);


//////// Timing //////////
unsigned long currentMillis;
unsigned long fpsMillis;
unsigned long cntfps = 1;  // we willen geen 0 om eventuele delingen door 0 te vermijden
