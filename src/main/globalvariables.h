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

//////// Timing //////////
unsigned long currentMillis;
unsigned long fpsMillis;
unsigned long cntfps = 1;  // we willen geen 0 om eventuele delingen door 0 te vermijden

//////// ledStrip //////////

// int str_startled[] = {
//       STR_OLI_0PLAF_STARTLED,
//       STR_OLI_0TRAP_STARTLED,
//       STR_OLI_1PLAF_STARTLED,
//       STR_SCR_0PLAF_STARTLED
//     };
// int str_stopled[] = {
//       STR_OLI_0PLAF_STOPLED,
//       STR_OLI_0TRAP_STOPLED,
//       STR_OLI_1PLAF_STOPLED,
//       STR_SCR_0PLAF_STOPLED
//     };
// int str_hue1[] = {
//       STR_OLI_0PLAF_HUE1,
//       STR_OLI_0TRAP_HUE1,
//       STR_OLI_1PLAF_HUE1,
//       STR_SCR_0PLAF_HUE1
//     };
// int str_sat1[] = {
//       STR_OLI_0PLAF_SAT1,
//       STR_OLI_0TRAP_SAT1,
//       STR_OLI_1PLAF_SAT1,
//       STR_SCR_0PLAF_SAT1
//     };
// int str_bright1[] = {
//       STR_OLI_0PLAF_BRIGHT1,
//       STR_OLI_0TRAP_BRIGHT1,
//       STR_OLI_1PLAF_BRIGHT1,
//       STR_SCR_0PLAF_BRIGHT1
//     };
// int str_hue2[] = {
//       STR_OLI_0PLAF_HUE2,
//       STR_OLI_0TRAP_HUE2,
//       STR_OLI_1PLAF_HUE2,
//       STR_SCR_0PLAF_HUE2
//     };
// int str_sat2[] = {
//       STR_OLI_0PLAF_SAT2,
//       STR_OLI_0TRAP_SAT2,
//       STR_OLI_1PLAF_SAT2,
//       STR_SCR_0PLAF_SAT2
//     };
// int str_bright2[] = {
//       STR_OLI_0PLAF_BRIGHT2,
//       STR_OLI_0TRAP_BRIGHT2,
//       STR_OLI_1PLAF_BRIGHT2,
//       STR_SCR_0PLAF_BRIGHT2
//     };
// int str_hue3[] = {
//       STR_OLI_0PLAF_HUE3,
//       STR_OLI_0TRAP_HUE3,
//       STR_OLI_1PLAF_HUE3,
//       STR_SCR_0PLAF_HUE3
//     };
// int str_sat3[] = {
//       STR_OLI_0PLAF_SAT3,
//       STR_OLI_0TRAP_SAT3,
//       STR_OLI_1PLAF_SAT3,
//       STR_SCR_0PLAF_SAT3
//     };
// int str_bright3[] = {
//       STR_OLI_0PLAF_BRIGHT3,
//       STR_OLI_0TRAP_BRIGHT3,
//       STR_OLI_1PLAF_BRIGHT3,
//       STR_SCR_0PLAF_BRIGHT3
//     };
// int str_hue4[] = {
//       STR_OLI_0PLAF_HUE4,
//       STR_OLI_0TRAP_HUE4,
//       STR_OLI_1PLAF_HUE4,
//       STR_SCR_0PLAF_HUE4
//     };
// int str_sat4[] = {
//       STR_OLI_0PLAF_SAT4,
//       STR_OLI_0TRAP_SAT4,
//       STR_OLI_1PLAF_SAT4,
//       STR_SCR_0PLAF_SAT4
//     };
// int str_bright4[] = {
//       STR_OLI_0PLAF_BRIGHT4,
//       STR_OLI_0TRAP_BRIGHT4,
//       STR_OLI_1PLAF_BRIGHT4,
//       STR_SCR_0PLAF_BRIGHT4
//     };
// int str_every[] = {
//       STR_OLI_0PLAF_EVERY,
//       STR_OLI_0TRAP_EVERY,
//       STR_OLI_1PLAF_EVERY,
//       STR_SCR_0PLAF_EVERY
//     };
// unsigned long str_time1[] = {
//       STR_OLI_0PLAF_TIME1,
//       STR_OLI_0TRAP_TIME1,
//       STR_OLI_1PLAF_TIME1,
//       STR_SCR_0PLAF_TIME1
//     };
// unsigned long str_time2[] = {
//       STR_OLI_0PLAF_TIME2,
//       STR_OLI_0TRAP_TIME2,
//       STR_OLI_1PLAF_TIME2,
//       STR_SCR_0PLAF_TIME2
//     };
// unsigned long str_tim_flick[] = {
//       STR_OLI_0PLAF_TIM_FLICK,
//       STR_OLI_0TRAP_TIM_FLICK,
//       STR_OLI_1PLAF_TIM_FLICK,
//       STR_SCR_0PLAF_TIM_FLICK
// };
