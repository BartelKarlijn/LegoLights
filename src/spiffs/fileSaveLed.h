#pragma once
String  fileSaveLed(int lednr) {
// Save Led settings to file
  char filename[18];
  JsonDocument doc;

  sprintf(filename, "/cfg_led%02d.ini", lednr);

  Print("Filename ");
  Println(String(filename));

  // write variables to JSON file
  doc["desc"]     = ledsingle[lednr].desc;
  doc["bri"]      = ledsingle[lednr].bri;
  doc["timeon"]   = ledsingle[lednr].timeon;
  doc["timeoff"]  = ledsingle[lednr].timeoff;
  doc["timeeffect"] = ledsingle[lednr].timeeffect;
  doc["effect"]   = ledsingle[lednr].effect;
  
  // write config file
  String tmp = "";
  serializeJson(doc, tmp);
  writeFile(SPIFFS, filename, tmp);
  
  return "Settings bewaard voor " + ledsingle[lednr].desc;
}
