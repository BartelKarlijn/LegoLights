#pragma once
String  fileHuisLoadSettings() {
// Load Huis settings from file
  char filename[18] = "/cfg_huis.ini";
  String msgAnswer;

  Print(String(filename));

  if (!SPIFFS.exists(filename)) {
    msgAnswer = "Huis config file does not exist, using defaults";
    
    for(int lednr=0; lednr<LED_NR_ITEMS; lednr++) {
//      ledsettings[lednr].leddesc          = LED_SINGLEDEFAULT.desc + String(lednr);
//      ledsettings[lednr].ledimage         = LED_SINGLEDEFAULT.image;
//      ledsettings[lednr].anim[0].animdesc = LED_SINGLEDEFAULT.animatie;
    }
  }
  
  return msgAnswer;
}
