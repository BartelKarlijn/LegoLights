#pragma once
String  fileHuisLoadSettings() {
// Load Huis settings from file
  char filename[18] = FILE_HUIS;
  String msgAnswer;

  Println(String(filename));

  if (!SPIFFS.exists(filename)) {
    msgAnswer = "Huis config file does not exist, using defaults";
    huisSetting.desc        = HUIS_DEFAULT.desc;
    huisSetting.image       = HUIS_DEFAULT.image;
    huisSetting.huisnr      = HUIS_DEFAULT.huisnr;
    huisSetting.animnrhuis  = HUIS_DEFAULT.animnrhuis;
    huisSetting.animdefault = HUIS_DEFAULT.animdefault;
    huisSetting.newMACadress = HUIS_DEFAULT.newMACadress;
    for (uint8_t i = 0; i < HUIS_NR_ANIM; i++) {
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

    huisSetting.huisnr      = doc["huisnr"].as<uint8_t>();
    huisSetting.desc        = doc["desc"].as<String>();
    huisSetting.image       = doc["image"].as<String>();
    huisSetting.animnrhuis  = doc["animnrhuis"].as<uint8_t>();
    huisSetting.animdefault = doc["animdefault"].as<uint8_t>();
    huisSetting.newMACadress = doc["newMACadress"].as<String>();
    for (uint8_t i = 0; i < HUIS_NR_ANIM; i++) {
      huisSetting.animdesc[i] = doc["animdesc"][i].as<String>();
    }

    msgAnswer = "Huissettings loaded for H" + String(huisSetting.huisnr) + " " + huisSetting.desc;
  }

  Println(msgAnswer);
  return msgAnswer;
}
