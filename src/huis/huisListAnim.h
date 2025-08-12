#pragma once
String huisListAnim() {
  // List the animations in the settings for a huis
  String msgAnswer="";

  for (size_t i = 0; i < HUIS_NR_ANIM; i++)
  {
      msgAnswer += "<option value='";
      msgAnswer += i;
      msgAnswer += "'>";
      msgAnswer += i;
      msgAnswer += ". ";
      msgAnswer += huisSetting.animdesc[i];
      msgAnswer += "</option>";
  }
  
  Println("List Anims for huis " + String(huisRequest.huisnr) );

  return msgAnswer;
}