// Configuration file for commands
// Define a type for the function pointers
typedef void (*FunctionPointer)();
struct str_command {
    String cmd;
    FunctionPointer function;
    String arguments;
    String desc;
};
void cC00Help();  // forward declaration

str_command validCommands[] = {// arg1 arg2 arg3       desc
    {"C00", cC00Help            , "-    -    -    " , "show this table" },
    {"F01", cF01fpsShow         , "0/1  -    -    " , "stop/show fps from now on" },
    {"K01", cK01kringSetJpg     , "krng jpeg -    " , "set jpeg for krng" },
    {"K02", cK02kringSetName    , "krng name -   " , "set name for krng" },
    {"K03", cK03kringStartStop  , "krng strt stop" , " set startled" },
    {"K04", cK04kringEvery      , "krng ever -   " , "set every" },
    {"K05", cK05kringHue        , "krng 1234 hue " , "set hue1/2/3/" },
    {"K06", cK06kringSat        , "krng 1234 sat " , "set sat1/2/3/" },
    {"K07", cK07kringBri        , "krng 1234 bri " , "set bri1/2/3/" },
    {"K08", cK08kringTonToff    , "krng tOn  tOff " , "set timeOn and timeOff" },
    {"K09", cK09kringEffect     , "krng eff  tEff " , "set effect" },
    {"K10", cK10kringSeed       , "krng seed      " , "set" },
    {"K20", cK20kringSaveSetting, "-    -    -    " , "save settings" },
    {"K21", cK21kringLoadSetting, "-    -    -    " , "load from last save" },
    {"K22", cK22kringDefaultSet , "-    -    -    " , "reload defaults" },
    {"L02", cL02ledSetName      , "led  name -    " , "set led name" },
    {"L07", cL07ledSetBrightness, "led  bri  -    " , "set brightness" },
    {"L08", cL08ledSetTimeOnOff , "led  tOn  tOff " , "set timeOn and timeOff" },
    {"L09", cL09ledSetEffect    , "led  eff  tEff " , "set effect" },
    {"L20", cL20ledSaveSetting  , "led  anim -    " , "save settings voor Animatie" },
    {"L21", cL21ledLoadSetting  , "led  -    -    " , "load from last save" },
//    {"L22", CL22ledDefaultSet   , "led  -    -    " , "reload defaults" },
    {"R01", cW01wifiShowNetworks, "x    -    -    " , "reboot in x sec" },
    {"R10", cW01wifiShowNetworks, "name -    -    " , "give board a name H01= Olivander, ..." },
    {"R20", cW01wifiShowNetworks, "-    -    -    " , "save settings" },
    {"R21", cW01wifiShowNetworks, "-    -    -    " , "load from last save" },
    {"R22", cW01wifiShowNetworks, "-    -    -    " , "reload defaults" },
    {"W01", cW01wifiShowNetworks, "-    -    -    " , "wifi show available networks" },
    {"W02", cW01wifiShowNetworks, "-    -    -    " , "wifi show ssid and pw" },
    {"W03", cW01wifiShowNetworks, "ssid pw   -    " , "wifi save ssid and pw" },
    {"W10", cW01wifiShowNetworks, "-    -    -    " , "startwifi & connect to network" },
    {"W11", cW01wifiShowNetworks, "-    -    -    " , "startwifi & setup AP" },
    {"W12", cW01wifiShowNetworks, "-    -    -    " , "stop wifi" }
};
