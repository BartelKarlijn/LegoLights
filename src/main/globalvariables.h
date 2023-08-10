
//////////////// OPERATION ///////////////////////
Preferences pref_eeprom;           // to store & read parameters from eprom

//////// Wifi //////////
// Create AsyncWebServer object on port 80
AsyncWebServer webserver(80);
//DNSServer dnsServer;    //Even afgezet want voor eigen AP wellicht niet nodig
String wifi_ssid ;
String wifi_pwd  ;
String wifi_scan;         //Lijst met scan van wifi netwerken
bool   flagWifiOn = false;

// handles voor wifi paginas
#define hdlRoot       "/"                        // handle voor hoofdscherm.  Hier kom je standaard op terecht
#define hdlKnop       "/knop"                    // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlUpdate     "/update"                  // Dit niet wijzigen: is voor OTA firmware 
#define hdlWifiPWD    "/wificfg"                 // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
//#define hdlWifiScan   "/wifiscan"                // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlWifiSave   "/wifisave"                // om daarna op te vangen welke knop is ingedrukt.  Best niet wijzigen, wordt vast in html_sendPage gebruikt
#define hdlWebSerial  "/webserial"               // Dit is niet te wijzigen, is om Serial Monitor via web te hebben
#define hdlTimeSave   "/timesave"                // handle to submit time

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

//////// ledStrip //////////
CRGB ledstrip[STR_NUM_LEDS];

int str_startled[] = {
      STR_OLI_0PLAF_STARTLED,
      STR_OLI_0TRAP_STARTLED
    };
int str_stopled[] = {
      STR_OLI_0PLAF_STOPLED,
      STR_OLI_0TRAP_STOPLED,
    };
CRGB str_color[] = {
      STR_OLI_0PLAF_COLOR,
      STR_OLI_0TRAP_COLOR,
    };
int str_brightn[] = {
      STR_OLI_0PLAF_BRIGHTN,
      STR_OLI_0TRAP_BRIGHTN,
    };