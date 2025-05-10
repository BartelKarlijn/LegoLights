#pragma once
String  fileSaveLed(int lednr, String animatie) {
// Save Led settings to file
  char filename[18];
  JsonDocument doc;
  // Create an array to represent the table
  JsonArray table = doc.to<JsonArray>();  
  // Add rows to the table
  JsonObject row;

  sprintf(filename, "/cfg_led%02d.ini", lednr);

  Print("Filename ");
  Println(String(filename));

  // write variables to JSON file
  row["animatie"] = animatie;
  row["desc"]     = ledsingle[lednr].desc;
  row["bri"]      = ledsingle[lednr].bri;
  row["timeon"]   = ledsingle[lednr].timeon;
  row["timeoff"]  = ledsingle[lednr].timeoff;
  row["timeeffect"] = ledsingle[lednr].timeeffect;
  row["effect"]   = ledsingle[lednr].effect;
  
  table.add(row);
  // write config file
  String tmp = "";
  serializeJson(doc, tmp);
  writeFile(SPIFFS, filename, tmp);
  
  return "Settings bewaard voor " + ledsingle[lednr].desc;
}
