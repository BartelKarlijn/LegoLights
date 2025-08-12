#pragma once
void loadAnimatie() {
  // Ini files zijn ingelezen.
  
  // leds
  for (size_t lednr = 0; lednr < LED_NR_ITEMS; lednr++)
  {
    ledRequest.lednr = lednr;
    ledRequest.animnr = huisSetting.animnrhuis;
    ledAnimApply();
  }
  
  // rgb
  for (size_t rgbnr = 0; rgbnr < RGB_NR_ITEMS; rgbnr++)
  {
    rgbRequest.rgbnr = rgbnr;
    rgbRequest.animnr = huisSetting.animnrhuis;
    rgbAnimApply();
  }
}
