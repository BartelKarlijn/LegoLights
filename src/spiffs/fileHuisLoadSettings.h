#pragma once
String  fileHuisLoadSettings() {
// Load Huis settings from file
  char filename[18] = FILE_HUIS;
  String msgAnswer;

  Print(String(filename));

  if (!SPIFFS.exists(filename)) {
    msgAnswer = "Huis config file does not exist, using defaults";
    huisSetting.desc        = HUIS_DEFAULT.desc;
    huisSetting.image       = HUIS_DEFAULT.image;
    huisSetting.huisnr      = HUIS_DEFAULT.huisnr;
    huisSetting.animnrhuis  = HUIS_DEFAULT.animnrhuis;
    huisSetting.animdefault = HUIS_DEFAULT.animdefault;
    for (size_t i = 0; i < HUIS_NR_ANIM; i++) {
      huisSetting.animdesc[i] = HUIS_DEFAULT.animdesc[i];
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

    huisSetting.huisnr      = doc["huisnr"].as<size_t>();
    huisSetting.desc        = doc["desc"].as<String>();
    huisSetting.image       = doc["image"].as<String>();
    huisSetting.animnrhuis  = doc["animnrhuis"].as<size_t>();
    huisSetting.animdefault = doc["animdefault"].as<size_t>();
    for (size_t i = 0; i < HUIS_NR_ANIM; i++) {
      huisSetting.animdesc[i] = doc["animdesc"][i].as<String>();
    }

    msgAnswer = "Huissettings loaded";
  }

  return msgAnswer;
}
