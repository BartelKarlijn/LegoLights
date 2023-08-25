#pragma once
String  loadkring(int kringnr) {
// Load Kring settings from file
  char filename[18];

  sprintf(filename, "/cfg_kring%02d.ini", kringnr);

  Print("Filename ");
  Println(String(filename));

  String file_content = readFile(SPIFFS, filename);
  int config_file_size = file_content.length();
  Println("Config file size: " + String(config_file_size));

  if(config_file_size > 1024) {
    Println("Config file too large");
    return "Config file too large";
  }

  StaticJsonDocument<1024> doc;
  auto error = deserializeJson(doc, file_content);
  if ( error ) { 
    Println("Error interpreting config file");
    return "Error interpreting config file";
  }

// write variables to JSON file
  const String _desc       = doc["desc"]; 
  const int    _startled   = doc["startled"];
  const int    _stopled    = doc["stopled"];
  const int    _hue1       = doc["hue1"];
  const int    _sat1       = doc["sat1"];
  const int    _bright1    = doc["bright1"];
  const int    _hue2       = doc["hue2"];
  const int    _sat2       = doc["sat2"];
  const int    _bright2    = doc["bright2"];
  const int    _hue3       = doc["hue3"];
  const int    _sat3       = doc["sat3"];
  const int    _bright3    = doc["bright3"];
  const int    _hue4       = doc["hue4"];
  const int    _sat4       = doc["sat4"];
  const int    _bright4    = doc["bright4"];
  const int    _every      = doc["every"];
  const unsigned long _timeon     = doc["timeon"];
  const unsigned long _timeoff    = doc["timeoff"];
  const unsigned long _timeeffect = doc["timeeffect"];
  const bool  _direction  = doc["direction"];
  const int  _effect     = doc["effect"];

  kring[kringnr].desc      = _desc;
  kring[kringnr].startled  = _startled;
  kring[kringnr].stopled   = _stopled;
  kring[kringnr].hue1      = _hue1;
  kring[kringnr].sat1      = _sat1;
  kring[kringnr].bright1   = _bright1;
  kring[kringnr].hue2      = _hue2;
  kring[kringnr].sat2      = _sat2;
  kring[kringnr].bright2   = _bright2;
  kring[kringnr].hue3      = _hue3;
  kring[kringnr].sat3      = _sat3;
  kring[kringnr].bright3   = _bright3;
  kring[kringnr].hue4      = _hue4;
  kring[kringnr].sat4      = _sat4;
  kring[kringnr].bright4   = _bright4;
  kring[kringnr].every     = _every;
  kring[kringnr].timeon    = _timeon;
  kring[kringnr].timeoff   = _timeoff;
  kring[kringnr].timeeffect = _timeeffect;
  kring[kringnr].direction = _direction;
  kring[kringnr].effect    = _effect;

  return ("Data opgehaald voor " + kring[kringnr].desc);
}
