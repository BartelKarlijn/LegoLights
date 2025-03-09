// Configuration file for commands
// Define a type for the function pointers
typedef void (*FunctionPointer)();
struct str_command {
    String cmd;
    FunctionPointer function;
};

str_command validCommands[] = {     
    {"W01", cW01wifiShowNetworks},
    {"W02", cW01wifiShowNetworks},
    {"W03", cW01wifiShowNetworks}
};

const std::vector<String> validCmds = 
//  cmd         arg1 arg2 arg3
{    "W01"   //  -    -    -    wifi show available networks
    ,"W02"   //  -    -    -    wifi show ssid and pw
    ,"W03"   //  ssid pw   -    wifi save ssid and pw
    ,"W10"   //  -    -    -    startwifi & connect to network
    ,"W11"   //  -    -    -    startwifi & setup AP
    ,"W12"   //  -    -    -    stop wifi
    ,"F01"   //  0/1  -    -    stop/show fps from now on
    ,"R01"   //  x    -    -    reboot in x sec
    ,"R10"   //  name -    -    give board a name H01= Olivander, ...
    ,"K01"   //  krng jpeg -    set jpeg for krng
    ,"K02"   //  krng name -    set name for krng
    ,"K03"   //  krng strt stop set startled
    ,"K04"   //  krng ever -    set every
    ,"K05"   //  krng 1234 hue  set hue1/2/3/4 to hue
    ,"K06"   //  krng 1234 sat  set sat1/2/3/4 to sat
    ,"K07"   //  krng 1234 bri  set bri1/2/3/4 to bri
    ,"K08"   //  krng tOn  tOff set timeOn and timeOff
    ,"K09"   //  krng eff  tEff set effect
    ,"K10"   //  krng seed      set
    ,"K20"   //  -    -    -    save settings
    ,"K21"   //  -    -    -    load from last save
    ,"K22"   //  -    -    -    reload defaults
    ,"L02"   //  name -    -    set led name
    ,"L07"   //  bri  -    -    set brightness
    ,"L08"   //  tOn  tOff -    set timeOn and timeOff
    ,"L09"   //  eff  tEff -    set effect
    ,"L20"   //  -    -    -    save settings
    ,"L21"   //  -    -    -    load from last save
    ,"L22"   //  -    -    -    reload defaults
};


