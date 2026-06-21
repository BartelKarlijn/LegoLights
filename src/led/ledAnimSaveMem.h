#pragma once
String ledAnimSaveMem() {
  // Save active settings to memory
  uint8_t lednr = ledRequest.lednr;
  uint8_t animnr = ledRequest.animnr;
  String answertoSend;

  ledsettings[lednr].leddesc                = ledactive[lednr].desc;
  ledsettings[lednr].ledimage               = ledactive[lednr].image;
  ledsettings[lednr].anim[animnr].bri       = ledactive[lednr].bri;
  ledsettings[lednr].anim[animnr].timeon    = ledactive[lednr].timeon;
  ledsettings[lednr].anim[animnr].timeoff   = ledactive[lednr].timeoff;
  ledsettings[lednr].anim[animnr].timeeffect = ledactive[lednr].timeeffect;
  ledsettings[lednr].anim[animnr].effect     = ledactive[lednr].effect;
  
  return("ledAnimSaveMem applied");
}