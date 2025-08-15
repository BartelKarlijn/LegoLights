#pragma once
String rgbAnimSaveMem() {
  // Save active settings to memory
  size_t rgbnr = rgbRequest.rgbnr;
  size_t animnr = rgbRequest.animnr;
  String answertoSend;

  rgbsettings[rgbnr].rgbdesc                = rgbactive[rgbnr].desc;
  rgbsettings[rgbnr].rgbimage               = rgbactive[rgbnr].image;
  rgbsettings[rgbnr].startrgb               = rgbactive[rgbnr].startrgb;
  rgbsettings[rgbnr].stoprgb                = rgbactive[rgbnr].stoprgb;
  rgbsettings[rgbnr].anim[animnr].hue1      = rgbactive[rgbnr].hue1;
  rgbsettings[rgbnr].anim[animnr].sat1      = rgbactive[rgbnr].sat1;
  rgbsettings[rgbnr].anim[animnr].bri1      = rgbactive[rgbnr].bri1;
  rgbsettings[rgbnr].anim[animnr].hue2      = rgbactive[rgbnr].hue2;
  rgbsettings[rgbnr].anim[animnr].sat2      = rgbactive[rgbnr].sat2;
  rgbsettings[rgbnr].anim[animnr].bri2      = rgbactive[rgbnr].bri2;
  rgbsettings[rgbnr].anim[animnr].hue3      = rgbactive[rgbnr].hue3;
  rgbsettings[rgbnr].anim[animnr].sat3      = rgbactive[rgbnr].sat3;
  rgbsettings[rgbnr].anim[animnr].bri3      = rgbactive[rgbnr].bri3;
  rgbsettings[rgbnr].anim[animnr].hue4      = rgbactive[rgbnr].hue4;
  rgbsettings[rgbnr].anim[animnr].sat4      = rgbactive[rgbnr].sat4;
  rgbsettings[rgbnr].anim[animnr].bri4      = rgbactive[rgbnr].bri4;
  rgbsettings[rgbnr].anim[animnr].every     = rgbactive[rgbnr].every;
  rgbsettings[rgbnr].anim[animnr].timeon    = rgbactive[rgbnr].timeon;
  rgbsettings[rgbnr].anim[animnr].timeoff   = rgbactive[rgbnr].timeoff;
  rgbsettings[rgbnr].anim[animnr].timeeffect = rgbactive[rgbnr].timeeffect;
  rgbsettings[rgbnr].anim[animnr].seed      = rgbactive[rgbnr].seed;
  rgbsettings[rgbnr].anim[animnr].effect    = rgbactive[rgbnr].effect;
  
  return("rgbAnimSaveMem applied");
}