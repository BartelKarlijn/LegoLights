#pragma once
String  fileLoad2Huis() {
// Load Huis settings from file
  char filename[18] = "/cfg_huis.ini";
  String msgAnswer;

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

    JsonDocument doc;
    auto error = deserializeJson(doc, file_content);
    if ( error ) { 
      Println("Error interpreting config file");
      msgAnswer ="Error interpreting config file";
    }

    // get variables from JSON file
    const str_huis _huis = {
      doc["huisnr"],
      doc["desc"],
      doc["image"]
   };
   huissetting     = _huis;
    
    msgAnswer = ("Data opgehaald voor " + huissetting.huisnr);
    Println("Nr" + String(_huis.huisnr) + "Desc: " + _huis.desc + ", img: " + _huis.image); delay(100);
  }
  return msgAnswer;
}
