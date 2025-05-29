//jpeg files
#define IMG_OLIV "file_img_Olivander.jpg"
#define IMG_QUID "file_img_Quiddich.jpg"
#define IMG_FLOU "file_img_Flourish.jpg"
#define IMG_WEAS "file_img_Weasley.jpg"

#define FILE_HUIS "/cfg_huis.ini"
#define FILE_LED  "/cfg_led.ini"
#define FILE_RGB  "/cfg_rgb.ini"

#define LED_NR_ITEMS 16
#define LED_NR_ANIM 6

#define RGB_NR_ITEMS 16
#define RGB_NR_ANIM 5
#define RGB_NR_LEDS 300 

// default waarden
#define STRIP_NR_ITEMS 40

// ------------------ Huis -----------------------
// -----------------------------------------------
typedef struct {
  int huisnr;
  String desc;
  String image;
  int    animnr[LED_NR_ITEMS];
} struc_huis;

const struc_huis HUIS_DEFAULT {
  0,
  "Huis",
  "file_img_Huis.jpg"
};
struc_huis huisSetting;

// ------------------ Led ------------------------
// -----------------------------------------------
// effecten leds
#define EFFLED_AAN     10
#define EFFLED_FIRE    11
#define EFFLED_GLOW    12
#define EFFLED_RAMP    13
#define EFFLED_RAND    14
#define EFFLED_UIT     15

typedef struct {
  String        desc;
  String        image;
  int           bri;    //4095 mogelijkheden
  unsigned long timeon;
  unsigned long timeoff;
  long          timeeffect;  //negatieve waarden toelaten
  uint8_t       effect;
  int           animnr;
  String        animatie;
} struc_ledactive;

typedef struct {
  String        animdesc;
  int           bri;    //4095 mogelijkheden
  unsigned long timeon;
  unsigned long timeoff;
  long          timeeffect;  //negatieve waarden toelaten
  uint8_t       effect;
} struc_ledanim;

typedef struct {
  String        leddesc;
  String        ledimage;
  struc_ledanim anim[LED_NR_ANIM];
} struc_ledsettings;

// default voor alle leds als er geen file is.
const struc_ledactive LEDACTIVE_DEFAULT  {"led", IMG_OLIV , 4095,  1000,   1000,    150, EFFLED_AAN ,  0, "default" };

struc_ledactive   ledactive[LED_NR_ITEMS];
struc_ledsettings ledsettings[LED_NR_ITEMS];

unsigned long timer_led_aan[LED_NR_ITEMS];
unsigned long time_led_eff[LED_NR_ITEMS];  //van begin aan tot eind van effect (gaat dus over meerder effecten heen)
unsigned long time_fase_beg[LED_NR_ITEMS];  //begin van een nieuwe fase
unsigned long time_fase_end[LED_NR_ITEMS];  //eind van een nieuwe fase
uint8_t       fase[LED_NR_ITEMS];  //welke fase zitten we (bv ramp fase 1=up, 2=on, 3=down, 4=off)
uint8_t       effectledbri[LED_NR_ITEMS];


// ------------------ Rgb ------------------------
// -----------------------------------------------
// Configuration file for default rgb coloring
// effecten rgb
#define EFFRGB_UIT      0
#define EFFRGB_AAN      1
#define EFFRGB_CHASE    2
#define EFFRGB_FIRE     3
#define EFFRGB_GLOW     4
#define EFFRGB_PARTY    5

typedef struct {
  String        desc;
  String        image;
  int           startrgb;
  int           stoprgb;
  uint8_t       hue1;
  uint8_t       sat1;
  uint8_t       bri1;
  uint8_t       hue2;
  uint8_t       sat2;
  uint8_t       bri2;
  uint8_t       hue3;
  uint8_t       sat3;
  uint8_t       bri3;
  uint8_t       hue4;
  uint8_t       sat4;
  uint8_t       bri4;
  uint8_t       every;
  unsigned long timeon;
  unsigned long timeoff;
  unsigned long timeeffect;
  int8_t        seed;
  uint8_t       effect;
} struc_rgbactive;

typedef struct {
  String        animdesc;
  uint8_t       hue1;
  uint8_t       sat1;
  uint8_t       bri1;
  uint8_t       hue2;
  uint8_t       sat2;
  uint8_t       bri2;
  uint8_t       hue3;
  uint8_t       sat3;
  uint8_t       bri3;
  uint8_t       hue4;
  uint8_t       sat4;
  uint8_t       bri4;
  uint8_t       every;
  unsigned long timeon;
  unsigned long timeoff;
  unsigned long timeeffect;
  int8_t        seed;
  uint8_t       effect;
} struc_rgbanim;

typedef struct {
  String        rgbdesc;
  String        rgbimage;
  int           startrgb;
  int           stoprgb;
  struc_rgbanim anim[LED_NR_ANIM];
} struc_rgbsettings;

// default voor alle leds als er geen file is.
//                                        desc, img      ,star,stop,hue1,sat1,bri1,hue2,sat2,bri2,hue3,sat3,bri3,hue4,sat4,bri4,every,timeon,timeoff,timeeff,seed,eff
const struc_rgbactive RGBACTIVE_DEFAULT  {"rgb", IMG_OLIV, 0  ,  10,   0,  10, 150, 255, 255, 255, 255, 255, 255, 255, 255, 255,    0,  1000,    150, 500, 0, EFFRGB_AAN };

struc_rgbactive   rgbactive[RGB_NR_ITEMS];
struc_rgbsettings rgbsettings[RGB_NR_ITEMS];

const struc_rgbactive STR_DEFAULT[] {
//234567890 234567890             hue 0:red   , 32: orange, 64: yellow, 128: aqua, 192: purple, 255:red                     dir 0: up, 1: down
//                                     sat 0: white -255 color                                      time : in ms                effect: zie begin van file
//    description (20) ,star,stop,hue1,sat1,bri1,hue2,sat2,bri2,hue3,sat3,bri3,hue4,sat4,bri4,every,timeon,timeoff,timeeff,seed,eff
 {"Olivander V0 plafon", IMG_OLIV ,   0,  10,  48, 255, 255,  48, 255,   0, 150, 255, 170, 150, 255,   0,    5, 10000,   1000,   2500,  0, EFFRGB_GLOW } // 0
,{"Olivander V0 trap  ", IMG_OLIV ,  11,  11, 192, 255, 255,  92, 255, 255,  80, 255,  70,  75, 255,  70,    1,  5000,   1000,    500,  0, EFFRGB_UIT  } // 1
,{"Olivander V1 plafon", IMG_OLIV ,  12,  22,  48, 255, 170,  60, 255,  70,  80, 255,  75,  75, 255,  70,    5, 10000,   1000,    500,  0, EFFRGB_UIT  } // 2
,{"Scribulus V1 plafon", IMG_OLIV ,  23,  29,  48, 200, 150, 150, 255, 100, 152, 255,   0,   0, 255,   0,    3, 10000,   1000,    500,  0, EFFRGB_CHASE} // 3
,{"Scribulus V1 haard ", IMG_OLIV ,  30,  30,  32, 255, 255,   0, 255, 255,  20, 255, 255,  10, 255, 255,    1, 10000,   1000,    100,  0, EFFRGB_FIRE } // 4
,{"Scribulus V1 vitrin", IMG_OLIV ,  31,  32, 152, 150, 220,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,      0,  0, EFFRGB_AAN  } // 5
,{"Scribulus V0 plafon", IMG_OLIV ,  33,  39,  48, 150, 150,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFRGB_AAN  } // 6
,{"Scribulus V0 pui   ", IMG_OLIV ,  40,  41, 140, 255, 100,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1,  5000,   1000,    250,  0, EFFRGB_AAN  } // 7
,{"Olivander V0 puiR  ", IMG_OLIV ,  42,  43,  64, 255, 100, 100, 255, 100,  90, 255, 100, 110, 255,  50,    1, 10000,   1000,    100,  0, EFFRGB_FIRE } // 8
,{"Olivander V0 puiL  ", IMG_OLIV ,  44,  45,  64, 255, 100, 100, 255, 100,  90, 255, 100, 110, 255,  50,    1, 10000,   1000,    100,  0, EFFRGB_FIRE } // 9
,{"Quiddich  GLV pop v", IMG_OLIV ,  46,  48,   0, 180, 200,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFRGB_AAN  } //10
,{"Quiddich  V1 plafon", IMG_OLIV ,  49,  72,   0, 255,   0,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1, 10000,   1000,    250,  0, EFFRGB_AAN  } //11
,{"Quiddich  V1 kast  ", IMG_OLIV ,  73,  82, 128, 255, 255,   0, 255,   0,   0, 255,   0,   0, 255,   0,    1,  1000,    250,    250,  0, EFFRGB_AAN  } //12
,{"Quiddich  V2 Dozen ", IMG_OLIV ,  83,  89,  32, 200, 100,   0, 255,   0,   0, 255,   0,   0, 255,   0,    6,   125,   5750,    250,  0, EFFRGB_AAN  } //13
};

struc_rgbactive kring[STRIP_NR_ITEMS];  //variabele om de waarden in bij te houden (default, uitlezen of aangepast)

// rgbstrip 
CRGB rgbstrip[RGB_NR_LEDS];

// timing & color varialbles
unsigned long timer_rgb_aan[STRIP_NR_ITEMS];
unsigned long timer_rgb_effect[STRIP_NR_ITEMS];
uint8_t effectrgbhueidx[STRIP_NR_ITEMS][4];
uint8_t effectrgbhue[STRIP_NR_ITEMS][4];
uint8_t effectrgbsat[STRIP_NR_ITEMS][4];
uint8_t effectrgbbri[STRIP_NR_ITEMS][4];
uint8_t chaseRgbNr[STRIP_NR_ITEMS][4];

//////////// single leds /////////////////////////////
