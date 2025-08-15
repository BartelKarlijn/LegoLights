#pragma once
String ledAnimApply() {
  // Apply LED settings for given animatie
  size_t lednr = ledRequest.lednr;
  size_t animnr = ledRequest.animnr;
  if (huisSetting.animdesc[animnr] == NULL) {
    Println("ledAnimApply: animatie niet gevonden nr " + String(animnr));
  }
  else {
    ledactive[lednr].desc       = ledsettings[lednr].leddesc;
    ledactive[lednr].bri        = ledsettings[lednr].anim[animnr].bri;
    ledactive[lednr].timeon     = ledsettings[lednr].anim[animnr].timeon;
    ledactive[lednr].timeoff    = ledsettings[lednr].anim[animnr].timeoff;
    ledactive[lednr].timeeffect = ledsettings[lednr].anim[animnr].timeeffect;
    ledactive[lednr].effect     = ledsettings[lednr].anim[animnr].effect;
    ledactive[lednr].image      = ledsettings[lednr].ledimage;
  }
  return "anim applied";
}
