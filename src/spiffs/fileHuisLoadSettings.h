#pragma once
String  fileHuisLoadSettings() {
// Load Huis settings from file
  char filename[18] = FILE_HUIS;
  String msgAnswer;

  Print(String(filename));

  if (!SPIFFS.exists(filename)) {
    msgAnswer = "Huis config file does not exist, using defaults";
    huisSetting.desc = HUIS_DEFAULT.desc;
    huisSetting.image = HUIS_DEFAULT.image;
    huisSetting.huisnr = HUIS_DEFAULT.huisnr;
    for(int lednr=0; lednr<LED_NR_ITEMS; lednr++) {
      huisSetting.animnr[lednr] = 0;
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

    huisSetting.huisnr = doc["huisnr"].as<int>();
    huisSetting.desc   = doc["desc"].as<String>();
    huisSetting.image  = doc["image"].as<String>();
    for (int lednr=0; lednr<LED_NR_ITEMS; lednr++) {
      huisSetting.animnr[lednr] = doc["animnr"][lednr].as<int>();
    }
  }

  return msgAnswer;
}
