// Configuration file for default led coloring
// effecten strip
#define EFFSTR_AAN      0
#define EFFSTR_CHASE    1
#define EFFSTR_FIRE     2
#define EFFSTR_GLOW     3
#define EFFSTR_PARTY    4
#define EFFSTR_UIT      5

//jpeg files
#define IMG_OLIV "file_img_Olivander.jpg"
#define IMG_QUID "file_img_Quiddich.jpg"
#define IMG_FLOU "file_img_Flourish.jpg"
#define IMG_WEAS "file_img_Weasley.jpg"
typedef struct {
  String desc;
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
  String image;
} str_strip;

// default waarden
#define STRIP_NR_ITEMS 40
#define STRIP_NR_LEDS 311 //eentje meer dan laatste item in lijstje hieronder

const str_strip STR_DEFAULT[STRIP_NR_ITEMS] {
//234567890 234567890             hue 0:red   , 32: orange, 64: yellow, 128: aqua, 192: purple, 255:red                     dir 0: up, 1: down
//                                     sat 0: white -255 color                                      time : in ms                effect: zie begin van file
//    description (20) ,star,stop,hue1,sat1,bri1,hue2,sat2,bri2,hue3,sat3,bri3,hue4,sat4,bri4,every,timeon,timeoff,timeeff, dir,eff
 {"Olivander V0 plafon",   0,  10,  48, 200, 170,   0, 255,  80, 150, 255,  80, 160, 255,  80,    1, 10000,   1000,    500,  0, EFFSTR_AAN  , IMG_OLIV } // 0
,{"Olivander V0 trap  ",  11,  11, 192, 255, 255,  92, 255, 255,  80, 255,  70,  75, 255,  70,    1,  5000,   1000,    500,  0, EFFSTR_GLOW , IMG_OLIV } // 1
,{"Olivander V1 plafon",  12,  22,  48, 255, 170,  60, 255,  70,  80, 255,  75,  75, 255,  70,    1, 10000,   1000,    500,  0, EFFSTR_AAN  , IMG_OLIV } // 2
,{"Scribulus V1 plafon",  23,  29,  48, 200, 150, 150, 255, 100, 152, 255,   0,   0, 255,   0,    1, 10000,   1000,    500,  0, EFFSTR_CHASE, IMG_OLIV } // 3
,{"Scribulus V1 haard ",  30,  30,  32, 255, 255,   0, 255, 255,  20, 255, 255,  10, 255, 255,    1, 10000,   1000,    100,  0, EFFSTR_FIRE , IMG_OLIV } // 4
,{"Scribulus V1 vitrin",  31,  32, 152, 150, 220,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,      0,  0, EFFSTR_AAN  , IMG_OLIV } // 5
,{"Scribulus V0 plafon",  33,  39,  48, 150, 150,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_OLIV } // 6
,{"Scribulus V0 pui   ",  40,  41, 140, 255, 100,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1,  5000,   1000,    250,  0, EFFSTR_GLOW , IMG_OLIV } // 7
,{"Olivander V0 puiR  ",  42,  43,  64, 255, 100, 100, 255, 100,  90, 255, 100, 110, 255,  50,    1, 10000,   1000,    100,  0, EFFSTR_FIRE , IMG_OLIV } // 8
,{"Olivander V0 puiL  ",  44,  45,  64, 255, 100, 100, 255, 100,  90, 255, 100, 110, 255,  50,    1, 10000,   1000,    100,  0, EFFSTR_FIRE , IMG_OLIV } // 9
,{"Quiddich  1        ",  46, 100,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_QUID } //10
,{"Quiddich  2        ", 101, 110,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_QUID } //11
,{"Quiddich  3        ", 111, 120,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_QUID } //12
,{"Quiddich  4        ", 121, 130,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_QUID } //13
,{"Quiddich  5        ", 131, 140,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_QUID } //14
,{"Quiddich  6        ", 141, 150,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_QUID } //15
,{"Quiddich  7        ", 151, 160,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_QUID } //16
,{"Quiddich  8        ", 161, 170,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_QUID } //17
,{"Quiddich  9        ", 171, 180,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_QUID } //18
,{"Quiddich 10        ", 181, 190,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_QUID } //19
,{"Flourish  1        ", 191, 192,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //20
,{"Flourish  2        ", 193, 194,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //21
,{"Flourish  3        ", 195, 196,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //22
,{"Flourish  4        ", 197, 198,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //23
,{"Flourish  5        ", 199, 200,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //24
,{"Flourish  6        ", 201, 202,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  , IMG_FLOU } //25
,{"Flourish  7        ", 203, 204,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  } //26
,{"Flourish  8        ", 205, 206,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  } //27
,{"Flourish  9        ", 207, 208,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  } //28
,{"Flourish 10        ", 209, 210,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  } //29
,{"Weasley   1        ", 211, 220,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  } //30
,{"Weasley   2        ", 221, 230,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  } //31
,{"Weasley   3        ", 231, 240,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  } //32
,{"Weasley   4        ", 241, 250,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  } //33
,{"Weasley   5        ", 251, 260,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  } //34
,{"Weasley   6        ", 261, 270,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  } //35
,{"Weasley   7        ", 271, 280,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  } //36
,{"Weasley   8        ", 281, 290,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  } //37
,{"Weasley   9        ", 291, 300,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  } //38
,{"Weasley  10        ", 301, 310,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFSTR_AAN  } //39
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
  int    bright;
  unsigned long timeon;
  unsigned long timeoff;
  unsigned long timeeffect;
  int    effect;
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
unsigned long time_led_eff[LED_NR_ITEMS];  //van time_aan tot eind van dit vlammetje
int flameledbright[LED_NR_ITEMS];
