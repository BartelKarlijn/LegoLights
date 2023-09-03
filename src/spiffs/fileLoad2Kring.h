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
      doc["bright1"],
      doc["hue2"],
      doc["sat2"],
      doc["bright2"],
      doc["hue3"],
      doc["sat3"],
      doc["bright3"],
      doc["hue4"],
      doc["sat4"],
      doc["bright4"],
      doc["every"],
      doc["timeon"],
      doc["timeoff"],
      doc["timeeffect"],
      doc["direction"],
      doc["effect"],
      doc["image"]
   };
   kring[kringnr]     = _kring;
    // kring[kringnr].startled  = _kring.startled;
    // kring[kringnr].stopled   = _kring.stopled;
    // kring[kringnr].hue1      = _kring.hue1;
    // kring[kringnr].sat1      = _kring.sat1;
    // kring[kringnr].sat1      = _kring.sat1;
    // kring[kringnr].bright1   = _kring.bright1;
    // kring[kringnr].hue2      = _kring.hue2;
    // kring[kringnr].sat2      = _kring.sat2;
    // kring[kringnr].bright2   = _kring.bright2;
    // kring[kringnr].hue3      = _kring.hue3;
    // kring[kringnr].sat3      = _kring.sat3;
    // kring[kringnr].bright3   = _kring.bright3;
    // kring[kringnr].hue4      = _kring.hue4;
    // kring[kringnr].sat4      = _kring.sat4;
    // kring[kringnr].bright4   = _kring.bright4;
    // kring[kringnr].every     = _kring.every;
    // kring[kringnr].timeon    = _timeon;
    // kring[kringnr].timeoff   = _timeoff;
    // kring[kringnr].timeeffect = _timeeffect;
    // kring[kringnr].direction = _direction;
    // kring[kringnr].effect    = _effect;
    // kring[kringnr].image     = _image;

    msgAnswer = ("Data opgehaald voor " + kring[kringnr].desc);
    Print("  Desc: " + _kring.desc + ", img: " + _kring.image + ", eff: " + _kring.effect); delay(100);
  }
  return msgAnswer;
}
