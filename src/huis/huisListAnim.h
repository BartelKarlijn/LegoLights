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
//      msgAnswer += huissettings[ledRequest.lednr].anim[i].animdesc;
      msgAnswer += "</option>";
  }
  
//  Println("List Anims for huis " + String(ledRequest.lednr));

  return msgAnswer;
}