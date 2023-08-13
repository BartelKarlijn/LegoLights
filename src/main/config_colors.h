// Configuration file for default led coloring
// effecten
#define EFFSTR_AAN      0
#define EFFSTR_CHASE    1
#define EFFSTR_FIRE     2
#define EFFSTR_GLOW     3
#define EFFSTR_PARTY    4
#define EFFSTR_UIT      5

// structure voor de ledstrip
typedef struct {
  char   desc[20];
  int    startled;
  int    stopled;
  int    hue1;
  int    sat1;
  int    bright1;
  int    hue2;
  int    sat2;
  int    bright2;
  int    hue3;
  int    sat3;
  int    bright3;
  int    hue4;
  int    sat4;
  int    bright4;
  int    every;
  unsigned long timeon;
  unsigned long timeoff;
  unsigned long timeeffect;
  bool   direction;
  int    effect;
} str_strip;

// default waarden
#define STRIP_NR_ITEMS 4
#define STRIP_NR_LEDS  21 //eentje meer dan laatste item in lijstje hieronder

const str_strip STR_DEFAULT[STRIP_NR_ITEMS] {
//234567890 234567890             hue 0:red   , 32: orange, 64: yellow, 128: aqua, 192: purple, 255:red                     dir 0: up, 1: down
//                                     sat 0: white -255 color                                      time : in ms                effect: zie begin van file
//    description (20) ,star,stop,hue1,sat1,bri1,hue2,sat2,bri2,hue3,sat3,bri3,hue4,sat4,bri4,every,timeon,timeoff,timeeff, dir,eff
 {"Olivander GLV plafo",   0,   0,   1, 255, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,    1, 10000,   1000,      0,  0, EFFSTR_AAN  }
,{"Olivander GLV trap ",   1,   1, 128, 255, 255,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1,  5000,   1000,      0,  0, EFFSTR_GLOW }
,{"Olivander V1 plafon",   2,   2,  25, 255, 255,  20, 255, 255,  15, 255, 255,  30, 255, 255,    1, 10000,   1000,    250,  0, EFFSTR_FIRE }
,{"Scribulus GLV plafo",   3,  18,   0, 255, 255,  84, 255, 255, 150, 255, 255, 230, 255, 255,    2, 10000,   1000,    500,  0, EFFSTR_PARTY}
};

str_strip str_kring[STRIP_NR_ITEMS];  //variabele om de waarden in bij te houden (default, uitlezen of aangepast)

// ledstrip 
CRGB ledstrip[STRIP_NR_LEDS];

// timing & color varialbles
unsigned long timer_str_aan[STRIP_NR_ITEMS];
unsigned long timer_str_flicker[STRIP_NR_ITEMS];
int flamestrhueidx[STRIP_NR_ITEMS];
int flamestrhue[STRIP_NR_ITEMS];
int flamestrsat[STRIP_NR_ITEMS];
int flamestrbright[STRIP_NR_ITEMS];
int chasestrnr[STRIP_NR_ITEMS];
