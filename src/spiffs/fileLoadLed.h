#pragma once
String  fileLoadLed(int lednr, String animatie) {
// Save Led settings to file
  char filename[18];
  //sprintf(filename, "/cfg_led%02d.ini", lednr);
  sprintf(filename, "/a.txt", lednr);

  Print("Filename ");
  Println(String(filename));

/*  JsonDocument doc;
  
  // Create an array to represent the table
  JsonArray table = doc.to<JsonArray>();  

  // Add rows to the table
  JsonObject row = table.createNestedObject();

  // first write default values to file
  row["animatie"] = "default";
  row["desc"]     = LED_DEFAULT[lednr].desc;
  row["bri"]      = LED_DEFAULT[lednr].bri;
  row["timeon"]   = LED_DEFAULT[lednr].timeon;
  row["timeoff"]  = LED_DEFAULT[lednr].timeoff;
  row["timeeffect"] = LED_DEFAULT[lednr].timeeffect;
  row["effect"]   = LED_DEFAULT[lednr].effect;
  table.add(row);
  
  // write variables to JSON file
  row["animatie"] = animatie;
  row["desc"]     = ledsingle[lednr].desc;
  row["bri"]      = ledsingle[lednr].bri;
  row["timeon"]   = ledsingle[lednr].timeon;
  row["timeoff"]  = ledsingle[lednr].timeoff;
  row["timeeffect"] = ledsingle[lednr].timeeffect;
  row["effect"]   = ledsingle[lednr].effect;
  
  table.add(row);
  Print("Json: ");
  Println(row["animatie"].as<String>());
  // write config file
  String tmp = "";
  serializeJson(doc, tmp);
  writeFile(SPIFFS, filename, tmp);
  */
  return "Settings opgeladen voor led " + ledsingle[lednr].desc;
}
