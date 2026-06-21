#pragma once
String rgbCopyFirstToAnim() {
  // Copy RGB settings from first animation (default) to the current animation
  uint8_t rgbnr = rgbRequest.rgbnr;
  uint8_t animnr = rgbRequest.animnr;
  if (huisSetting.animdesc[animnr] == NULL) {
    Println("rgbCopyFirstToAnim: animatie niet gevonden");
  }
  else {
    Println("rgbCopyFirstToAnim: rgb=" + String(rgbnr) + ", anim= " + String(animnr) );
    rgbsettings[rgbnr].anim[animnr].hue1       = rgbsettings[rgbnr].anim[0].hue1;
    rgbsettings[rgbnr].anim[animnr].sat1       = rgbsettings[rgbnr].anim[0].sat1;
    rgbsettings[rgbnr].anim[animnr].bri1       = rgbsettings[rgbnr].anim[0].bri1;
    rgbsettings[rgbnr].anim[animnr].hue2       = rgbsettings[rgbnr].anim[0].hue2;
    rgbsettings[rgbnr].anim[animnr].sat2       = rgbsettings[rgbnr].anim[0].sat2;
    rgbsettings[rgbnr].anim[animnr].bri2       = rgbsettings[rgbnr].anim[0].bri2;
    rgbsettings[rgbnr].anim[animnr].hue3       = rgbsettings[rgbnr].anim[0].hue3;
    rgbsettings[rgbnr].anim[animnr].sat3       = rgbsettings[rgbnr].anim[0].sat3;
    rgbsettings[rgbnr].anim[animnr].bri3       = rgbsettings[rgbnr].anim[0].bri3;
    rgbsettings[rgbnr].anim[animnr].hue4       = rgbsettings[rgbnr].anim[0].hue4;
    rgbsettings[rgbnr].anim[animnr].sat4       = rgbsettings[rgbnr].anim[0].sat4;
    rgbsettings[rgbnr].anim[animnr].bri4       = rgbsettings[rgbnr].anim[0].bri4;
    rgbsettings[rgbnr].anim[animnr].every      = rgbsettings[rgbnr].anim[0].every;
    rgbsettings[rgbnr].anim[animnr].timeon     = rgbsettings[rgbnr].anim[0].timeon;
    rgbsettings[rgbnr].anim[animnr].timeoff    = rgbsettings[rgbnr].anim[0].timeoff;
    rgbsettings[rgbnr].anim[animnr].timeeffect = rgbsettings[rgbnr].anim[0].timeeffect;
    rgbsettings[rgbnr].anim[animnr].seed       = rgbsettings[rgbnr].anim[0].seed;
    rgbsettings[rgbnr].anim[animnr].effect     = rgbsettings[rgbnr].anim[0].effect;

    rgbactive[rgbnr].hue1       = rgbsettings[rgbnr].anim[animnr].hue1;
    rgbactive[rgbnr].sat1       = rgbsettings[rgbnr].anim[animnr].sat1;
    rgbactive[rgbnr].bri1       = rgbsettings[rgbnr].anim[animnr].bri1;
    rgbactive[rgbnr].hue2       = rgbsettings[rgbnr].anim[animnr].hue2;
    rgbactive[rgbnr].sat2       = rgbsettings[rgbnr].anim[animnr].sat2;
    rgbactive[rgbnr].bri2       = rgbsettings[rgbnr].anim[animnr].bri2;
    rgbactive[rgbnr].hue3       = rgbsettings[rgbnr].anim[animnr].hue3;
    rgbactive[rgbnr].sat3       = rgbsettings[rgbnr].anim[animnr].sat3;
    rgbactive[rgbnr].bri3       = rgbsettings[rgbnr].anim[animnr].bri3;
    rgbactive[rgbnr].hue4       = rgbsettings[rgbnr].anim[animnr].hue4;
    rgbactive[rgbnr].sat4       = rgbsettings[rgbnr].anim[animnr].sat4;
    rgbactive[rgbnr].bri4       = rgbsettings[rgbnr].anim[animnr].bri4;
    rgbactive[rgbnr].every      = rgbsettings[rgbnr].anim[animnr].every;
    rgbactive[rgbnr].timeon     = rgbsettings[rgbnr].anim[animnr].timeon;
    rgbactive[rgbnr].timeoff    = rgbsettings[rgbnr].anim[animnr].timeoff;
    rgbactive[rgbnr].timeeffect = rgbsettings[rgbnr].anim[animnr].timeeffect;
    rgbactive[rgbnr].seed       = rgbsettings[rgbnr].anim[animnr].seed;
    rgbactive[rgbnr].effect     = rgbsettings[rgbnr].anim[animnr].effect;
  }
  return "settings copied";
}
