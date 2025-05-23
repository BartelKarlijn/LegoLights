#pragma once
String ledListAnim() {
  // List the animations in the settings for a led
  String msgAnswer="";

  for (size_t i = 0; i < LED_NR_ANIM; i++)
  {
    if(!(ledsettings[ledRequest.lednr].anim[i].animdesc == NULL)) {
      msgAnswer += "<option value='";
      msgAnswer += i;
      msgAnswer += "'>";
      msgAnswer += ledsettings[ledRequest.lednr].anim[i].animdesc;
      msgAnswer += "</option>";
    }
    
  }
  
  Println("settingLedListAnim: " + msgAnswer);

  return msgAnswer;
}