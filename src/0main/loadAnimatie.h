#pragma once
void loadAnimatie() {
  // Ini files zijn ingelezen.
  
  // leds
  for (uint8_t lednr = 0; lednr < LED_NR_ITEMS; lednr++)
  {
    ledRequest.lednr  = lednr;
    ledRequest.animnr = huisSetting.animdefault;
    ledAnimApply();
  }
  
  // rgb
  for (uint8_t rgbnr = 0; rgbnr < RGB_NR_ITEMS; rgbnr++)
  {
    rgbRequest.rgbnr  = rgbnr;
    rgbRequest.animnr = huisSetting.animdefault;
    rgbAnimApply();
  }
}
