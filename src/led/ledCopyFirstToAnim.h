#pragma once
String ledCopyFirstToAnim() {
  // Copy LED settings from first animation (default) to the current animation
  size_t lednr = ledRequest.lednr;
  size_t animnr = huisSetting.animnrhuis;
  if (huisSetting.animdesc[animnr] == NULL) {
    Println("ledCopyFirstToAnim: animatie niet gevonden");
  }
  else {
    Println("ledCopyFirstToAnim: led=" + String(lednr) + ", anim= " + String(animnr) );
    ledsettings[lednr].anim[animnr].bri        = ledsettings[lednr].anim[0].bri;
    ledsettings[lednr].anim[animnr].timeon     = ledsettings[lednr].anim[0].timeon;
    ledsettings[lednr].anim[animnr].timeoff    = ledsettings[lednr].anim[0].timeoff;
    ledsettings[lednr].anim[animnr].timeeffect = ledsettings[lednr].anim[0].timeeffect;
    ledsettings[lednr].anim[animnr].effect     = ledsettings[lednr].anim[0].effect;

    ledactive[lednr].bri        = ledsettings[lednr].anim[0].bri;
    ledactive[lednr].timeon     = ledsettings[lednr].anim[0].timeon;
    ledactive[lednr].timeoff    = ledsettings[lednr].anim[0].timeoff;
    ledactive[lednr].timeeffect = ledsettings[lednr].anim[0].timeeffect;
    ledactive[lednr].effect     = ledsettings[lednr].anim[0].effect;
  }
  return "settings copied";
}
