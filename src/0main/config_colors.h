//jpeg files
#define IMG_OLIV "file_img_Olivander.jpg"
#define IMG_QUID "file_img_Quiddich.jpg"
#define IMG_FLOU "file_img_Flourish.jpg"
#define IMG_WEAS "file_img_Weasley.jpg"

#define FILE_HUIS "/cfg_huis.ini"
#define FILE_LED  "/cfg_led.ini"
#define FILE_RGB  "/cfg_rgb.ini"

#define HUIS_NR_ANIM 5

#define LED_NR_ITEMS 16
#define LED_NR_ANIM 6

#define RGB_NR_ITEMS 16
#define RGB_NR_ANIM 5
#define RGB_NR_LEDS 100 

// ------------------ Huis -----------------------
// -----------------------------------------------
typedef struct {
  size_t huisnr;
  String desc;
  String image;
  size_t animdefault;  // bij opstarten
  size_t animnrhuis;  // huidige anim
  String newMACadress; // New MAC adress to use for this huis, if 00:00:00:00:00:00 then use default MAC
  String animdesc[HUIS_NR_ANIM];
} struc_huis;

const struc_huis HUIS_DEFAULT {
  0,
  "Huis",
  "file_img_Huis.jpg",
  0,
  0,
  "23:5F:32:C1:ED:00",
  {"Anim 0", "Anim 1", "Anim 2", "Anim 3", "Anim 4"},
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
  size_t        bri;    //4095 mogelijkheden
  unsigned long timeon;
  unsigned long timeoff;
  long          timeeffect;  //negatieve waarden toelaten
  uint8_t       effect;
} struc_ledactive;

typedef struct {
//  String        animdesc;
  size_t        bri;    //4095 mogelijkheden
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
const struc_ledactive LEDACTIVE_DEFAULT  {"led", IMG_OLIV , 4095,  1000,   1000,    150, EFFLED_AAN };

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
  size_t        startrgb;
  size_t        stoprgb;
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
//  String        animdesc;
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
  size_t        startrgb;
  size_t        stoprgb;
  struc_rgbanim anim[LED_NR_ANIM];
} struc_rgbsettings;

// default voor alle leds als er geen file is.
//                                        desc, img      ,star,stop,hue1,sat1,bri1,hue2,sat2,bri2,hue3,sat3,bri3,hue4,sat4,bri4,every,timeon,timeoff,timeeff,seed,eff
const struc_rgbactive RGBACTIVE_DEFAULT  {"rgb", IMG_OLIV, 0  ,  10,   0,  10, 150, 255, 255, 255, 255, 255, 255, 255, 255, 255,    0,  1000,    150, 500, 0, EFFRGB_AAN };

struc_rgbactive   rgbactive[RGB_NR_ITEMS];
struc_rgbsettings rgbsettings[RGB_NR_ITEMS];

// rgbstrip 
CRGB rgbstrip[RGB_NR_LEDS];

// timing & color varialbles
unsigned long timer_rgb_aan[RGB_NR_ITEMS];
unsigned long timer_rgb_effect[RGB_NR_ITEMS];
uint8_t effectrgbhueidx[RGB_NR_ITEMS][4];
uint8_t effectrgbhue[RGB_NR_ITEMS][4];
uint8_t effectrgbsat[RGB_NR_ITEMS][4];
uint8_t effectrgbbri[RGB_NR_ITEMS][4];
uint8_t chaseRgbNr[RGB_NR_ITEMS][4];
