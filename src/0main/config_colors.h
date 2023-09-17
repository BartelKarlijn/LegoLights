// Configuration file for default led coloring
// effecten strip
#define EFFSTR_UIT      0
#define EFFSTR_AAN      1
#define EFFSTR_CHASE    2
#define EFFSTR_FIRE     3
#define EFFSTR_GLOW     4
#define EFFSTR_PARTY    5

//jpeg files
#define IMG_OLIV "file_img_Olivander.jpg"
#define IMG_QUID "file_img_Quiddich.jpg"
#define IMG_FLOU "file_img_Flourish.jpg"
#define IMG_WEAS "file_img_Weasley.jpg"
typedef struct {
  String desc;
  int startled;
  int stopled;
  uint8_t hue1;
  uint8_t sat1;
  uint8_t bri1;
  uint8_t hue2;
  uint8_t sat2;
  uint8_t bri2;
  uint8_t hue3;
  uint8_t sat3;
  uint8_t bri3;
  uint8_t hue4;
  uint8_t sat4;
  uint8_t bri4;
  uint8_t every;
  unsigned long timeon;
  unsigned long timeoff;
  unsigned long timeeffect;
  int8_t  seed;
  uint8_t effect;
  String  image;
} str_strip;

// default waarden
#define STRIP_NR_ITEMS 40
#define STRIP_NR_LEDS 311 //eentje meer dan laatste item in lijstje hieronder

const str_strip STR_DEFAULT[STRIP_NR_ITEMS] {
//234567890 234567890             hue 0:red   , 32: orange, 64: yellow, 128: aqua, 192: purple, 255:red                     dir 0: up, 1: down
//                                     sat 0: white -255 color                                      time : in ms                effect: zie begin van file
//    description (20) ,star,stop,hue1,sat1,bri1,hue2,sat2,bri2,hue3,sat3,bri3,hue4,sat4,bri4,every,timeon,timeoff,timeeff,seed,eff
 {"Olivander V0 plafon",   0,  10,  48, 255, 255,  48, 255,   0, 150, 255, 170, 150, 255,   0,    5, 10000,   1000,   2500,  0, EFFSTR_GLOW , IMG_OLIV } // 0
,{"Olivander V0 trap  ",  11,  11, 192, 255, 255,  92, 255, 255,  80, 255,  70,  75, 255,  70,    1,  5000,   1000,    500,  0, EFFSTR_UIT  , IMG_OLIV } // 1
,{"Olivander V1 plafon",  12,  22,  48, 255, 170,  60, 255,  70,  80, 255,  75,  75, 255,  70,    5, 10000,   1000,    500,  0, EFFSTR_UIT  , IMG_OLIV } // 2
,{"Scribulus V1 plafon",  23,  29,  48, 200, 150, 150, 255, 100, 152, 255,   0,   0, 255,   0,    3, 10000,   1000,    500,  0, EFFSTR_CHASE, IMG_OLIV } // 3
,{"Scribulus V1 haard ",  30,  30,  32, 255, 255,   0, 255, 255,  20, 255, 255,  10, 255, 255,    1, 10000,   1000,    100,  0, EFFSTR_FIRE , IMG_OLIV } // 4
,{"Scribulus V1 vitrin",  31,  32, 152, 150, 220,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,      0,  0, EFFSTR_AAN  , IMG_OLIV } // 5
,{"Scribulus V0 plafon",  33,  39,  48, 150, 150,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_OLIV } // 6
,{"Scribulus V0 pui   ",  40,  41, 140, 255, 100,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1,  5000,   1000,    250,  0, EFFSTR_AAN , IMG_OLIV } // 7
,{"Olivander V0 puiR  ",  42,  43,  64, 255, 100, 100, 255, 100,  90, 255, 100, 110, 255,  50,    1, 10000,   1000,    100,  0, EFFSTR_FIRE , IMG_OLIV } // 8
,{"Olivander V0 puiL  ",  44,  45,  64, 255, 100, 100, 255, 100,  90, 255, 100, 110, 255,  50,    1, 10000,   1000,    100,  0, EFFSTR_FIRE , IMG_OLIV } // 9
,{"Quiddich  GLV pop v",  46,  48,   0, 180, 200,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_QUID } //10
,{"Quiddich  V1 plafon",  49,  72,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_QUID } //11
,{"Quiddich  V1 kast  ",  73,  82, 128, 255, 255,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1,  1000,    250,    250,  0, EFFSTR_AAN , IMG_QUID } //12
,{"Quiddich  V2 Dozen ",  83,  89,  32, 200, 100,   0, 255,   0,   0, 255,   0,   0, 255,   0,    6,   125,   5750,    250,  0, EFFSTR_AAN , IMG_QUID } //13
,{"Quiddich  V2 Rat   ",  90,  96,  32, 200, 100,   0, 255,   0,   0, 255,   0,   0, 255,   0,    3,   125,   5750,    250,  0, EFFSTR_AAN  , IMG_QUID } //14
,{"Daily Spin         ",  97, 110, 192, 128, 150, 172, 128, 150, 152, 128, 150, 192, 180, 150,    2, 10000,   1000,     50,  0, EFFSTR_FIRE , IMG_QUID } //15
,{"Daily Profet GLV   ", 110, 123,  32, 100, 250,  32, 150,  50,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    100,  0, EFFSTR_AAN  , IMG_QUID } //16
,{"Quiddich GLV Plafon", 123, 146,   0, 255, 200,   0, 255,   0,   0, 255,   0,   0, 255,   0,    2, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_QUID } //17
,{"Quiddich GLV Bezem ", 147, 154,   0, 150, 200,   0, 200, 200,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,     75,  0, EFFSTR_CHASE, IMG_QUID } //18
,{"Quiddich GLV Afdak ", 155, 174,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_QUID } //19
,{"Flourish  1        ", 191, 192,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //20
,{"Flourish  2        ", 193, 194,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //21
,{"Flourish  3        ", 195, 196,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //22
,{"Flourish  4        ", 197, 198,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //23
,{"Flourish  5        ", 199, 200,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //24
,{"Flourish  6        ", 201, 202,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //25
,{"Flourish  7        ", 203, 204,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //26
,{"Flourish  8        ", 205, 206,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //27
,{"Flourish  9        ", 207, 208,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //28
,{"Flourish 10        ", 209, 210,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //29
,{"Weasley   1        ", 211, 220,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_WEAS } //30
,{"Weasley   2        ", 221, 230,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_WEAS } //31
,{"Weasley   3        ", 231, 240,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_WEAS } //32
,{"Weasley   4        ", 241, 250,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_WEAS } //33
,{"Weasley   5        ", 251, 260,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_WEAS } //34
,{"Weasley   6        ", 261, 270,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_WEAS } //35
,{"Weasley   7        ", 271, 280,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_WEAS } //36
,{"Weasley   8        ", 281, 290,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_WEAS } //37
,{"Weasley   9        ", 291, 300,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_WEAS } //38
,{"Weasley  10        ", 301, 310,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_WEAS } //39
//,{"Scribulus V1 plafoN",  19,  26, 192, 255, 255, 192, 255,  25,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,     80,  0, EFFSTR_CHASE}
};

str_strip kring[STRIP_NR_ITEMS];  //variabele om de waarden in bij te houden (default, uitlezen of aangepast)

// ledstrip 
CRGB ledstrip[STRIP_NR_LEDS];

// timing & color varialbles
unsigned long timer_str_aan[STRIP_NR_ITEMS];
unsigned long timer_str_effect[STRIP_NR_ITEMS];
uint8_t effectstrhueidx[STRIP_NR_ITEMS][4];
uint8_t effectstrhue[STRIP_NR_ITEMS][4];
uint8_t effectstrsat[STRIP_NR_ITEMS][4];
uint8_t effectstrbri[STRIP_NR_ITEMS][4];
uint8_t chasestrnr[STRIP_NR_ITEMS][4];

//////////// single leds /////////////////////////////
// effecten leds
#define EFFLED_AAN     10
#define EFFLED_FIRE    11
#define EFFLED_GLOW    12
#define EFFLED_UIT     13

typedef struct {
  char    desc[20];
  int     bri;    //4095 mogelijkheden
  unsigned long timeon;
  unsigned long timeoff;
  long    timeeffect;  //negatieve waarden toelaten
  uint8_t effect;
} str_ledsingle;

#define LED_NR_ITEMS 16
const str_ledsingle LED_DEFAULT[LED_NR_ITEMS] {
//    description (20) ,brigh,timeon,timeoff,timeeff, eff
 {"Olivander kaars    ", 4095, 10000,   1000,    150, EFFLED_FIRE  }
,{"Olivander lantaarn ", 2095, 10000,   1000,    400, EFFLED_FIRE }
,{"Olivander fakkel   ", 4095, 10000,   1000,    100, EFFLED_FIRE }
,{"led test04         ", 3095,   500,    500,      0, EFFLED_AAN  }
,{"led test05         ", 4095,   500,    500,      0, EFFLED_AAN  }
,{"led test06         ", 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test07         ", 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test08         ", 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test09         ", 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test10         ", 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test11         ", 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test12         ", 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test13         ", 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test14         ", 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test15         ", 4095,  1000,   1000,      0, EFFLED_AAN  }
,{"led test16         ", 4095,  1000,   1000,      0, EFFLED_AAN  }
};

str_ledsingle ledsingle[LED_NR_ITEMS];
unsigned long timer_led_aan[LED_NR_ITEMS];
unsigned long time_led_eff[LED_NR_ITEMS];  //van begin aan tot eind van effect (gaat dus over meerder effecten heen)
uint8_t effectledbri[LED_NR_ITEMS];
