#pragma once
String  fileSaveLed(int lednr, String animatie) {
// Save Led settings to file
char filename[18];
String msgAnswer;
bool flagFileExists = true;
bool flagAppend = true;
JsonDocument doc;
JsonDocument record;

String key;

sprintf(filename, "/cfg_led%02d.ini", lednr);

Print("Filename ");
Println(String(filename));

if (!SPIFFS.exists(filename)) {
  Println(" does not exist");
  flagFileExists = false;
  msgAnswer = "File does not exist";
}
else {
  String file_content = readFile(SPIFFS, filename);
  int config_file_size = file_content.length();
  Println(" size: " + String(config_file_size));

  if(config_file_size > 1024) {
    Println(" too large");
    msgAnswer ="Config file too large";
  }

  //bestaande file inlezen
  auto error = deserializeJson(doc, file_content);
  if ( error ) { 
    Println("Error interpreting config file");
    msgAnswer ="Error interpreting config file";
  }
  else {
    Println("doclengte: " + String(doc.size()));
    for (JsonPair kv : doc.as<JsonObject>()) {
      key = kv.key().c_str();
      if (key == animatie) {
        flagAppend = false;
      }
      Print("Key: " + key);
      Print(" Value: ");
      Println(kv.value().as<String>());
    }

  }
  // de records aanmaken:
  record["desc"] = LED_DEFAULT[lednr].desc;
  record["bri"] = LED_DEFAULT[lednr].bri;
  record["timeon"] = LED_DEFAULT[lednr].timeon;
  record["timeoff"] = LED_DEFAULT[lednr].timeoff;
  record["timeeffect"] = LED_DEFAULT[lednr].timeeffect;
  record["effect"] = LED_DEFAULT[lednr].effect;


  if (flagAppend) {
    doc[animatie] = record;
  }
  else {
    // update record
    doc[animatie] = record;
  }

    
/*

  JsonArray table = doc.to<JsonArray>();  

  // Add rows to the table
  JsonObject row = table.createNestedObject();

  sprintf(filename, "/cfg_led%02d.ini", lednr);

  Print("Filename ");
  Println(String(filename));

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
*/
  // write config file
    String tmp = "";
    serializeJson(doc, tmp);
    writeFile(SPIFFS, filename, tmp);
  }
  Println(fileListLed(lednr));
  
  return "Settings bewaard voor " + ledsingle[lednr].desc;

}
