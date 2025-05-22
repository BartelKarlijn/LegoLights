#pragma once
String settingledListAnim(int lednr) {
  // List the animations in the settings for a led
  String msgAnswer="";

  for (size_t i = 0; i < LED_NR_ANIM; i++)
  {
    if(!(ledsettings[lednr].anim[i].animdesc == NULL)) {
      msgAnswer += "<option value='";
      msgAnswer += i;
      msgAnswer += "'>";
      msgAnswer += ledsettings[lednr].anim[i].animdesc;
      msgAnswer += "</option>";
    }
    
  }
  
  Println("settingLedListAnim: " + msgAnswer);

  return msgAnswer;
}