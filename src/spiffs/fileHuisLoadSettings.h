#pragma once
String  fileHuisLoadSettings() {
// Load Huis settings from file
  char filename[18] = "/cfg_huis.ini";
  String msgAnswer;

  Print(String(filename));

  if (!SPIFFS.exists(filename)) {
    msgAnswer = "Huis config file does not exist, using defaults";
    huissetting.desc = HUIS_DEFAULT.desc;
    huissetting.image = HUIS_DEFAULT.image;
    huissetting.huisnr = HUIS_DEFAULT.huisnr;
    for(int lednr=0; lednr<LED_NR_ITEMS; lednr++) {
      huissetting.animnr[lednr] = HUIS_DEFAULT.animnr[lednr];
    }
  }
  else {
    String file_content = readFile(SPIFFS, filename);
    int config_file_size = file_content.length();
    Println(" size: " + String(config_file_size));

    JsonDocument doc;

    auto error = deserializeJson(doc, file_content);
    if ( error ) { 
      msgAnswer ="Error interpreting config file Led";
    }
    
  }

  return msgAnswer;
}
