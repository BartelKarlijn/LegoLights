#pragma once
String ledAnimApply() {
  // Apply LED settings for given animatie
  size_t lednr = ledRequest.lednr;
  size_t animnr = huisSetting.animnrhuis;
  if (huisSetting.animdesc[animnr] == NULL) {
    Println("settingLedApplyAnim: animatie niet gevonden");
  }
  else {
    Println("settingLedApplyAnim: " + huisSetting.animdesc[animnr]);
    ledactive[lednr].desc       = ledsettings[lednr].leddesc;
    ledactive[lednr].bri        = ledsettings[lednr].anim[animnr].bri;
    ledactive[lednr].timeon     = ledsettings[lednr].anim[animnr].timeon;
    ledactive[lednr].timeoff    = ledsettings[lednr].anim[animnr].timeoff;
    ledactive[lednr].timeeffect = ledsettings[lednr].anim[animnr].timeeffect;
    ledactive[lednr].effect     = ledsettings[lednr].anim[animnr].effect;
    ledactive[lednr].image      = ledsettings[lednr].ledimage;
    ledactive[lednr].animnr     = animnr;
    ledactive[lednr].animatie   = ledsettings[lednr].anim[animnr].animdesc;
  }
  return "anim applied";
}
