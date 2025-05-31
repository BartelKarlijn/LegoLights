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
    for(size_t lednr=0; lednr<LED_NR_ITEMS; lednr++) {
      huisSetting.animnrled[lednr] = 0;
    }
    for(size_t rgbnr=0; rgbnr<RGB_NR_ITEMS; rgbnr++) {
      huisSetting.animnrrgb[rgbnr] = 0;
    }
  }
  else {
    String file_content = readFile(SPIFFS, filename);
    size_t config_file_size = file_content.length();
    Println(" size: " + String(config_file_size));

    JsonDocument doc;

    auto error = deserializeJson(doc, file_content);
    if ( error ) { 
      msgAnswer ="Error interpreting config file Led";
    }

    huisSetting.huisnr = doc["huisnr"].as<size_t>();
    huisSetting.desc   = doc["desc"].as<String>();
    huisSetting.image  = doc["image"].as<String>();
    for (size_t lednr=0; lednr<LED_NR_ITEMS; lednr++) {
      huisSetting.animnrled[lednr] = doc["animnrled"][lednr].as<size_t>();
    }
    for (size_t rgbnr=0; rgbnr<RGB_NR_ITEMS; rgbnr++) {
      huisSetting.animnrrgb[rgbnr] = doc["animnrrgb"][rgbnr].as<size_t>();
    }
    msgAnswer = "Huissettings loaded";
  }

  return msgAnswer;
}
