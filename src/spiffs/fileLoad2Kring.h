#pragma once
String  fileLoad2Kring(int kringnr) {
// Load Kring settings from file
  char filename[18];
  String msgAnswer;

  sprintf(filename, "/cfg_kring%02d.ini", kringnr);

  Print(String(filename));

  if (!SPIFFS.exists(filename)) {
    Println(" does not exist");
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

    StaticJsonDocument<1024> doc;
    auto error = deserializeJson(doc, file_content);
    if ( error ) { 
      Println("Error interpreting config file");
      msgAnswer ="Error interpreting config file";
    }

    // get variables from JSON file
    const str_strip _kring = {
      doc["desc"],
      doc["startled"],
      doc["stopled"],
      doc["hue1"],
      doc["sat1"],
      doc["bri1"],
      doc["hue2"],
      doc["sat2"],
      doc["bri2"],
      doc["hue3"],
      doc["sat3"],
      doc["bri3"],
      doc["hue4"],
      doc["sat4"],
      doc["bri4"],
      doc["every"],
      doc["timeon"],
      doc["timeoff"],
      doc["timeeffect"],
      doc["seed"],
      doc["effect"],
      doc["image"]
   };
   kring[kringnr]     = _kring;
    
    msgAnswer = ("Data opgehaald voor " + kring[kringnr].desc);
    Print("  Desc: " + _kring.desc + ", img: " + _kring.image + ", eff: " + _kring.effect); delay(100);
  }
  return msgAnswer;
}
