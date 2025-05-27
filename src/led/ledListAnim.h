#pragma once
String ledListAnim() {
  // List the animations in the settings for a led
  String msgAnswer="";

  for (size_t i = 0; i < LED_NR_ANIM; i++)
  {
      msgAnswer += "<option value='";
      msgAnswer += i;
      msgAnswer += "'>";
      msgAnswer += i;
      msgAnswer += ". ";
      msgAnswer += ledsettings[ledRequest.lednr].anim[i].animdesc;
      msgAnswer += "</option>";
  }
  
  Println("List Anims for led " + String(ledRequest.lednr));

  return msgAnswer;
}