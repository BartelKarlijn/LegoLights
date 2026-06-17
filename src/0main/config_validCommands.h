// Configuration file for commands
// Define a type for the function pointers
typedef void (*FunctionPointer)();
typedef String (*FunctPointerWifi)(AsyncWebServerRequest *request);
struct struc_command {
    String cmd;
    FunctionPointer function;
    String arguments;
    String desc;
};
void cC00Help();  // forward declaration

struc_command validCommands[] = {// arg1 arg2 arg3       desc
    {"C00", cC00Help            , "-    -    -    " , "show this table" },
    {"A01", cA01applyAnim       , "0..5 -    -    " , "apply anim" },
    {"F01", cF01fpsShow         , "0/1  -    -    " , "stop/show fps from now on" },
    {"L02", cL02ledSetName      , "led  name -    " , "set led name" },
    {"L07", cL07ledSetBrightness, "led  bri  -    " , "set brightness" },
    {"L08", cL08ledSetTimeOnOff , "led  tOn  tOff " , "set timeOn and timeOff" },
    {"L09", cL09ledSetEffect    , "led  eff  tEff " , "set effect" },
    {"L20", cL20ledSaveSetting  , "led  anim -    " , "save settings voor Animatie" },
    {"L21", cL21ledLoadSetting  , "led  anim -    " , "load animation from last save" },
    {"R01", cR01rgbSetJpg       , "rgb  jpeg -    " , "set jpeg for rgb" },
    {"R02", cR02rgbSetName      , "rgb  name -   " , "set name for rgb" },
    {"R03", cR03rgbStartStop    , "rgb  strt stop" , " set startrgb" },
    {"R04", cR04rgbEvery        , "rgb  ever -   " , "set every" },
    {"R05", cR05rgbHue          , "rgb  1234 hue " , "set hue1/2/3/" },
    {"R06", cR06rgbSat          , "rgb  1234 sat " , "set sat1/2/3/" },
    {"R07", cR07rgbBri          , "rgb  1234 bri " , "set bri1/2/3/" },
    {"R08", cR08rgbTonToff      , "rgb  tOn  tOff " , "set timeOn and timeOff" },
    {"R09", cR09rgbEffect       , "rgb  eff  tEff " , "set effect" },
    {"R10", cR10rgbSeed         , "rgb  seed      " , "set" },
    {"W01", cW01wifiShowNetworks, "x    -    -    " , "reboot in x sec" },
    {"W02", cW01wifiShowNetworks, "name -    -    " , "give board a name H01= Olivander, ..." },
    {"W03", cW01wifiShowNetworks, "-    -    -    " , "save settings" },
    {"W04", cW01wifiShowNetworks, "-    -    -    " , "load from last save" },
    {"W05", cW01wifiShowNetworks, "-    -    -    " , "reload defaults" },
    {"W06", cW01wifiShowNetworks, "-    -    -    " , "wifi show available networks" },
    {"W07", cW01wifiShowNetworks, "-    -    -    " , "wifi show ssid and pw" },
    {"W08", cW01wifiShowNetworks, "ssid pw   -    " , "wifi save ssid and pw" },
    {"W09", cW01wifiShowNetworks, "-    -    -    " , "startwifi & connect to network" },
    {"W10", cW01wifiShowNetworks, "-    -    -    " , "startwifi & setup AP" },
    {"W11", cW01wifiShowNetworks, "-    -    -    " , "stop wifi" }
};

////// wifi comands ////////
struct struc_wifiRequest {
    String reqPrefix;
    String reqExt;
    bool iscmd;
    String htmltype;
    FunctPointerWifi function;    // zie hoger voor de definitie hiervan
};

#define MAX_WIFI_REQUEST 5
struc_wifiRequest validWifiRequest[] = {
    //begin , ext   , iscmd, htmltype, function
    {"/page", "html", false, "text/html"        , NULL},
    {"/file", "jpg" , false, "image/jpg"        , NULL},
    {"/file", "js"  , false, "text/javascript"  , NULL},
    {"/file", "ico" , false, "image/png"        , NULL},
    {"/file", "css" , false, "text/css"         , NULL}
//    {"/get" , "Led"   , true, "text/plain", on_getLed   },
//    {"/get" , "SetLed", true, "text/plain", on_getSetLed},
};
