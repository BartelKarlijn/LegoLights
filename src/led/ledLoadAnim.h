#pragma once
String ledLoadAnim() {
  // Ini files zijn ingelezen, nog eens toepassen wat daar staat
  for (size_t lednr = 0; lednr < LED_NR_ITEMS; lednr++)
  {
    ledRequest.lednr  = lednr;
    ledRequest.animnr = huisSetting.animnrhuis;
    ledAnimApply();
  }
  return("ledLoadAnim applied");
}