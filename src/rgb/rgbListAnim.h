#pragma once
String rgbListAnim() {
  // List the animations in the settings for a rgb
  String msgAnswer="";

  for (size_t i = 0; i < RGB_NR_ANIM; i++)
  {
      msgAnswer += "<option value='";
      msgAnswer += i;
      msgAnswer += "'>";
      msgAnswer += i;
      msgAnswer += ". ";
      msgAnswer += rgbsettings[rgbRequest.rgbnr].anim[i].animdesc;
      msgAnswer += "</option>";
  }
  
  Println("List Anims for rgb " + String(rgbRequest.rgbnr));

  return msgAnswer;
}