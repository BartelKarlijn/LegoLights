#pragma once
String huisAnimApply() {
  // Apply Huis settings for given animatie
  size_t animnr = huisRequest.animnr;
  if (huisSetting.animdesc[animnr] == NULL) {
    Println("huisApplyAnim: animatie niet gevonden");
  }
  else {
    Println("huisApplyAnim: " + String(animnr) + ", desc= " + huisSetting.animdesc[animnr]);
    // Apply anim to huisSetting
    huisSetting.animnrhuis = animnr;
    // Apply the animation to all leds
    for (size_t i = 0; i < LED_NR_ITEMS; i++) {
      ledRequest.lednr = i;
      ledAnimApply();
    }
    // Apply the animation to all rgb
    for (size_t i = 0; i < RGB_NR_ITEMS; i++) {
      rgbRequest.rgbnr = i;
      rgbAnimApply();
    }
  }
  return "anim applied";
}
