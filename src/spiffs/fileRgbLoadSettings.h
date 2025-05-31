#pragma once
String  fileRgbLoadSettings() {
// Load all Rgb settings into memory
  char filename[18]= FILE_RGB;
  String msgAnswer;

  Print("Filename ");
  Println(String(filename));

  if (!SPIFFS.exists(filename)) {
    msgAnswer = "Rgb config file does not exist, using defaults";
    for(size_t rgbnr=0; rgbnr<RGB_NR_ITEMS; rgbnr++) {
      rgbsettings[rgbnr].rgbdesc          = RGBACTIVE_DEFAULT.desc + String(rgbnr);
      rgbsettings[rgbnr].rgbimage         = RGBACTIVE_DEFAULT.image;
      rgbsettings[rgbnr].startrgb         = RGBACTIVE_DEFAULT.startrgb;
      rgbsettings[rgbnr].stoprgb          = RGBACTIVE_DEFAULT.stoprgb;
      rgbsettings[rgbnr].anim[0].hue1     = RGBACTIVE_DEFAULT.hue1;
      rgbsettings[rgbnr].anim[0].sat1     = RGBACTIVE_DEFAULT.sat1;
      rgbsettings[rgbnr].anim[0].bri1     = RGBACTIVE_DEFAULT.bri1;
      rgbsettings[rgbnr].anim[0].hue2     = RGBACTIVE_DEFAULT.hue2;
      rgbsettings[rgbnr].anim[0].sat2     = RGBACTIVE_DEFAULT.sat2;
      rgbsettings[rgbnr].anim[0].bri2     = RGBACTIVE_DEFAULT.bri2;
      rgbsettings[rgbnr].anim[0].hue3     = RGBACTIVE_DEFAULT.hue3;
      rgbsettings[rgbnr].anim[0].sat3     = RGBACTIVE_DEFAULT.sat3;
      rgbsettings[rgbnr].anim[0].bri3     = RGBACTIVE_DEFAULT.bri3;
      rgbsettings[rgbnr].anim[0].hue4     = RGBACTIVE_DEFAULT.hue4;
      rgbsettings[rgbnr].anim[0].sat4     = RGBACTIVE_DEFAULT.sat4;
      rgbsettings[rgbnr].anim[0].bri4     = RGBACTIVE_DEFAULT.bri4;
      rgbsettings[rgbnr].anim[0].every    = RGBACTIVE_DEFAULT.every;
      rgbsettings[rgbnr].anim[0].timeon   = RGBACTIVE_DEFAULT.timeon;
      rgbsettings[rgbnr].anim[0].timeoff  = RGBACTIVE_DEFAULT.timeoff;
      rgbsettings[rgbnr].anim[0].timeeffect = RGBACTIVE_DEFAULT.timeeffect;
      rgbsettings[rgbnr].anim[0].seed     = RGBACTIVE_DEFAULT.seed;
      rgbsettings[rgbnr].anim[0].effect   = RGBACTIVE_DEFAULT.effect;
    }

  }
  else {
    String file_content = readFile(SPIFFS, filename);
    size_t config_file_size = file_content.length();
    Println(" size: " + String(config_file_size));

    JsonDocument doc;

    auto error = deserializeJson(doc, file_content);
    if ( error ) { 
      msgAnswer ="Error interpreting config file Rgb";
    }

    size_t regelcounter = 0;
    JsonArray jrgbarr = doc.as<JsonArray>();
    Println("aantal rgbs: " + String(jrgbarr.size()));
    for (size_t rgbnr=0; rgbnr<jrgbarr.size(); rgbnr++) {
      rgbsettings[rgbnr].rgbdesc          = jrgbarr[rgbnr]["rgbdesc"].as<String>();
      rgbsettings[rgbnr].rgbimage         = jrgbarr[rgbnr]["rgbimage"].as<String>();
      rgbsettings[rgbnr].startrgb         = jrgbarr[rgbnr]["startrgb"].as<size_t>();
      rgbsettings[rgbnr].stoprgb          = jrgbarr[rgbnr]["stoprgb"].as<size_t>();
      Print(String(rgbnr)+" desc: " + jrgbarr[rgbnr]["rgbdesc"].as<String>());

      JsonArray janimarr = jrgbarr[rgbnr]["anim"].as<JsonArray>();
      Println(" aantal anims: " + String(janimarr.size()));
      for (size_t animnr=0; animnr<janimarr.size(); animnr++) {
        rgbsettings[rgbnr].anim[animnr].animdesc    = janimarr[animnr]["animdesc"].as<String>();
        rgbsettings[rgbnr].anim[animnr].hue1        = janimarr[animnr]["hue1"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].sat1        = janimarr[animnr]["sat1"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].bri1        = janimarr[animnr]["bri1"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].hue2        = janimarr[animnr]["hue2"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].sat2        = janimarr[animnr]["sat2"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].bri2        = janimarr[animnr]["bri2"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].hue3        = janimarr[animnr]["hue3"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].sat3        = janimarr[animnr]["sat3"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].bri3        = janimarr[animnr]["bri3"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].hue4        = janimarr[animnr]["hue4"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].sat4        = janimarr[animnr]["sat4"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].bri4        = janimarr[animnr]["bri4"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].every       = janimarr[animnr]["every"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].timeon      = janimarr[animnr]["timeon"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].timeoff     = janimarr[animnr]["timeoff"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].timeeffect  = janimarr[animnr]["timeeffect"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].seed        = janimarr[animnr]["seed"].as<size_t>();
        rgbsettings[rgbnr].anim[animnr].effect      = janimarr[animnr]["effect"].as<size_t>();
        regelcounter++; 
      }

    }

      msgAnswer = "Settings geladen voor " + String(regelcounter) + " rgbanimaties";

  }
  Println(msgAnswer);
  return msgAnswer;
}
