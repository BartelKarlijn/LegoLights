#pragma once
void settingLedApplyAnim(int lednr, int animnr) {
  // Apply LED settings for given animatie
  if (ledsettings[lednr].anim[animnr].animdesc == NULL) {
    Println("settingLedApplyAnim: animatie niet gevonden");
  }
  else {
    Println("settingLedApplyAnim: " + ledsettings[lednr].anim[animnr].animdesc);
    ledsingle[lednr].desc = ledsettings[lednr].leddesc;
    ledsingle[lednr].bri = ledsettings[lednr].anim[animnr].bri;
    ledsingle[lednr].timeon = ledsettings[lednr].anim[animnr].timeon;
    ledsingle[lednr].timeoff = ledsettings[lednr].anim[animnr].timeoff;
    ledsingle[lednr].timeeffect = ledsettings[lednr].anim[animnr].timeeffect;
    ledsingle[lednr].effect = ledsettings[lednr].anim[animnr].effect;
    ledsingle[lednr].image = ledsettings[lednr].ledimage;
    ledsingle[lednr].animnr = animnr;
    ledsingle[lednr].animatie = ledsettings[lednr].anim[animnr].animdesc;
  }
}
