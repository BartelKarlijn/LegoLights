#pragma once
String rgbLoadAnim() {
  // Ini files zijn ingelezen, nog eens toepassen wat daar staat
  for (size_t rgbnr = 0; rgbnr < RGB_NR_ITEMS; rgbnr++)
  {
    rgbRequest.rgbnr = rgbnr;
    rgbRequest.animnr = huisSetting.animnrrgb[rgbnr];
    rgbAnimApply();
  } 
  return("rgbLoadAnim applied");
}