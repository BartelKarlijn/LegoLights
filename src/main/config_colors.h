// Configuration file for default led coloring
// effecten strip
#define EFFSTR_AAN      0
#define EFFSTR_CHASE    1
#define EFFSTR_FIRE     2
#define EFFSTR_GLOW     3
#define EFFSTR_PARTY    4
#define EFFSTR_UIT      5

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
#define STRIP_NR_ITEMS 8
#define STRIP_NR_LEDS  30 //eentje meer dan laatste item in lijstje hieronder

const str_strip STR_DEFAULT[STRIP_NR_ITEMS] {
//234567890 234567890             hue 0:red   , 32: orange, 64: yellow, 128: aqua, 192: purple, 255:red                     dir 0: up, 1: down
//                                     sat 0: white -255 color                                      time : in ms                effect: zie begin van file
//    description (20) ,star,stop,hue1,sat1,bri1,hue2,sat2,bri2,hue3,sat3,bri3,hue4,sat4,bri4,every,timeon,timeoff,timeeff, dir,eff
 {"Scribulus GLV onder",   0,   1, 150, 255,  80, 145, 255,  80, 150, 255,  80, 160, 255,  80,    1, 10000,   1000,    500,  0, EFFSTR_FIRE }
,{"Olivander GLV ondeR",   2,   3,  64, 255,  70,  60, 255,  70,  80, 255,  70,  75, 255,  70,    1, 10000,   1000,    500,  0, EFFSTR_FIRE }
,{"Olivander GLV ondeL",   4,   5,  64, 255,  70,  60, 255,  70,  80, 255,  75,  75, 255,  70,    1, 10000,   1000,    500,  0, EFFSTR_FIRE }
,{"Olivander GLV plafo",   6,  18,   0, 255, 255,  84, 255, 255, 150, 255, 255, 230, 255, 255,    2, 10000,   1000,    500,  0, EFFSTR_PARTY}
,{"Olivander GLV plafo",  19,  30,   1, 255, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,    1, 10000,   1000,      0,  0, EFFSTR_AAN  }
,{"Olivander GLV trap ",  31,  40, 128, 255, 128,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1,  5000,   1000,      0,  0, EFFSTR_GLOW }
,{"Olivander V1 plafon",  41,  60,  25, 255, 128,  20, 255, 255,  15, 255, 255,  30, 255, 255,    1, 10000,   1000,    250,  0, EFFSTR_FIRE }
,{"Scribulus GLV plafo",  61,  99,   0, 255, 128,  84, 255, 255, 150, 255, 255, 230, 255, 255,    2, 10000,   1000,    500,  0, EFFSTR_PARTY}
//,{"Scribulus V1 plafoN",  19,  26, 192, 255, 255, 192, 255,  25,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,     80,  0, EFFSTR_CHASE}
};

str_strip kring[STRIP_NR_ITEMS];  //variabele om de waarden in bij te houden (default, uitlezen of aangepast)

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

//////////// single leds /////////////////////////////
// effecten leds
#define EFFLED_AAN     10
#define EFFLED_FIRE    11
#define EFFLED_GLOW    12
#define EFFLED_UIT     13

typedef struct {
  char   desc[20];
  int    lednr;
  int    bright;
  unsigned long timeon;
  unsigned long timeoff;
  unsigned long timeeffect;
  int    effect;
} str_ledsingle;

#define LED_NR_ITEMS 16
const str_ledsingle LED_DEFAULT[LED_NR_ITEMS] {
//    description (20) ,lednr,brigh,timeon,timeoff,timeeff, eff
 {"led geel           ",    0, 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test02         ",    1, 4095,   500,    500,      0, EFFLED_AAN  }
,{"led test03         ",    2, 2095,   500,    500,      0, EFFLED_AAN  }
,{"led test04         ",    3, 3095,   500,    500,      0, EFFLED_AAN  }
,{"led test05         ",    4, 4095,   500,    500,      0, EFFLED_AAN  }
,{"led test06         ",    5, 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test07         ",    6, 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test08         ",    7, 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test09         ",    8, 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test10         ",    9, 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test11         ",   10, 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test12         ",   11, 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test13         ",   12, 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test14         ",   13, 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test15         ",   14, 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test16         ",   15, 4095,  1000,   1000,      0, EFFLED_AAN  }
};

str_ledsingle ledsingle[LED_NR_ITEMS];
unsigned long timer_led_aan[LED_NR_ITEMS];
unsigned long timer_led_flicker[LED_NR_ITEMS];
