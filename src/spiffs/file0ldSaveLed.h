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
  record["desc"]      = ledsingle[lednr].desc;
  record["bri"]       = ledsingle[lednr].bri;
  record["timeon"]    = ledsingle[lednr].timeon;
  record["timeoff"]   = ledsingle[lednr].timeoff;
  record["timeeffect"] = ledsingle[lednr].timeeffect;
  record["effect"]    = ledsingle[lednr].effect;
  record["image"]     = ledsingle[lednr].image;
  record["animatie"]  = animatie;


  if (flagAppend) {
    doc[animatie] = record;
  }
  else {
    // update record
    doc[animatie] = record;
  }

  // write config file
    String tmp = "";
    serializeJson(doc, tmp);
    writeFile(SPIFFS, filename, tmp);
  }
  Println(fileListLed(lednr));

  return "Settings bewaard voor " + ledsingle[lednr].desc;

}
