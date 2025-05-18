#pragma once
void loadAnimatie() {
  String msgReceive;
  // Ini files zijn ingelezen.
  
  // leds
  for (size_t lednr = 0; lednr < LED_NR_ITEMS; lednr++)
  {
    settingLedApplyAnim(lednr, huissetting.animnr[lednr]);
  }
  
  // kringen
  for (size_t i = 0; i < STRIP_NR_ITEMS; i++) {
    if (fileLoad2Kring(i) == "File does not exist") {
      Println("Fallback to default for " + String(i)); delay(5);
      msgReceive = fileDefault2Kring(i);
    };
  }
}
