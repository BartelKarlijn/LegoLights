#pragma once
String rgbAnimApply() {
  // Apply RGB settings for given animatie
  size_t rgbnr = rgbRequest.rgbnr;
  size_t animnr = rgbRequest.animnr;
  if (huisSetting.animdesc[animnr] == NULL) {
    Println("rgbAnimApply: animatie niet gevonden nr " + String(animnr));
  }
  else {
    rgbactive[rgbnr].desc       = rgbsettings[rgbnr].rgbdesc;
    rgbactive[rgbnr].image      = rgbsettings[rgbnr].rgbimage;
    rgbactive[rgbnr].startrgb   = rgbsettings[rgbnr].startrgb;
    rgbactive[rgbnr].stoprgb    = rgbsettings[rgbnr].stoprgb;
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
  return "anim applied";
}
