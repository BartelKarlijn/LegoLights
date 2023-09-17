#pragma once
String  fileSaveKring(int kringnr) {
// Save Kring settings to file
  char filename[18];
  StaticJsonDocument<1024> doc;

  sprintf(filename, "/cfg_kring%02d.ini", kringnr);

  Print("Filename ");
  Println(String(filename));

  // write variables to JSON file
  doc["desc"]     = kring[kringnr].desc;
  doc["startled"] = kring[kringnr].startled;
  doc["stopled"]  = kring[kringnr].stopled;
  doc["hue1"]     = kring[kringnr].hue1;
  doc["sat1"]     = kring[kringnr].sat1;
  doc["bri1"]  = kring[kringnr].bri1;
  doc["hue2"]     = kring[kringnr].hue2;
  doc["sat2"]     = kring[kringnr].sat2;
  doc["bri2"]  = kring[kringnr].bri2;
  doc["hue3"]     = kring[kringnr].hue3;
  doc["sat3"]     = kring[kringnr].sat3;
  doc["bri3"]  = kring[kringnr].bri3;
  doc["hue4"]     = kring[kringnr].hue4;
  doc["sat4"]     = kring[kringnr].sat4;
  doc["bri4"]  = kring[kringnr].bri4;
  doc["every"]    = kring[kringnr].every;
  doc["timeon"]   = kring[kringnr].timeon;
  doc["timeoff"]  = kring[kringnr].timeoff;
  doc["timeeffect"] = kring[kringnr].timeeffect;
  doc["seed"]     = kring[kringnr].seed;
  doc["effect"]   = kring[kringnr].effect;
  doc["image"]    = kring[kringnr].image;

  // write config file
  String tmp = "";
  serializeJson(doc, tmp);
  writeFile(SPIFFS, filename, tmp);
  
  return "Settings bewaard voor " + kring[kringnr].desc;
}
