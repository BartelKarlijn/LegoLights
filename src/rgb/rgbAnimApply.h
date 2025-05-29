#pragma once
String rgbAnimApply() {
  // Apply LED settings for given animatie
  int lednr = ledRequest.lednr;
  int animnr = ledRequest.animnr;
  if (ledsettings[lednr].anim[animnr].animdesc == NULL) {
    Println("settingLedApplyAnim: animatie niet gevonden");
  }
  else {
    Println("settingLedApplyAnim: " + ledsettings[lednr].anim[animnr].animdesc);
    ledactive[lednr].desc = ledsettings[lednr].leddesc;
    ledactive[lednr].bri = ledsettings[lednr].anim[animnr].bri;
    ledactive[lednr].timeon = ledsettings[lednr].anim[animnr].timeon;
    ledactive[lednr].timeoff = ledsettings[lednr].anim[animnr].timeoff;
    ledactive[lednr].timeeffect = ledsettings[lednr].anim[animnr].timeeffect;
    ledactive[lednr].effect = ledsettings[lednr].anim[animnr].effect;
    ledactive[lednr].image = ledsettings[lednr].ledimage;
    ledactive[lednr].animnr = animnr;
    ledactive[lednr].animatie = ledsettings[lednr].anim[animnr].animdesc;
  }
  return "anim applied";
}
