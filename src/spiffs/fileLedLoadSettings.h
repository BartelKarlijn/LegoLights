#pragma once
String  fileLedLoadSettings() {
// Load all Led settings into memory
  char filename[18]= FILE_LED;
  String msgAnswer;

  Print("Filename ");
  Println(String(filename));

  if (!SPIFFS.exists(filename)) {
    msgAnswer = "Led config file does not exist, using defaults";
    for(uint8_t lednr=0; lednr<LED_NR_ITEMS; lednr++) {
      ledsettings[lednr].leddesc          = LEDACTIVE_DEFAULT.desc + String(lednr);
      ledsettings[lednr].ledimage         = LEDACTIVE_DEFAULT.image;
      ledsettings[lednr].anim[0].bri      = LEDACTIVE_DEFAULT.bri;
      ledsettings[lednr].anim[0].timeon   = LEDACTIVE_DEFAULT.timeon;
      ledsettings[lednr].anim[0].timeoff  = LEDACTIVE_DEFAULT.timeoff;
      ledsettings[lednr].anim[0].timeeffect = LEDACTIVE_DEFAULT.timeeffect;
      ledsettings[lednr].anim[0].effect   = LEDACTIVE_DEFAULT.effect;
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

    size_t regelcounter = 0;
    JsonArray jledarr = doc.as<JsonArray>();
    Println("aantal leds: " + String(jledarr.size()));
    for (uint8_t lednr=0; lednr<jledarr.size(); lednr++) {
      ledsettings[lednr].leddesc          = jledarr[lednr]["leddesc"].as<String>();
      ledsettings[lednr].ledimage         = jledarr[lednr]["ledimage"].as<String>();
      Print(String(lednr)+" desc: " + jledarr[lednr]["leddesc"].as<String>());

      JsonArray janimarr = jledarr[lednr]["anim"].as<JsonArray>();
      Println(" aantal anims: " + String(janimarr.size()));
      for (uint8_t animnr=0; animnr<janimarr.size(); animnr++) {
        ledsettings[lednr].anim[animnr].bri         = janimarr[animnr]["bri"].as<uint16_t>();
        ledsettings[lednr].anim[animnr].timeon      = janimarr[animnr]["timeon"].as<unsigned long>();
        ledsettings[lednr].anim[animnr].timeoff     = janimarr[animnr]["timeoff"].as<unsigned long>();
        ledsettings[lednr].anim[animnr].timeeffect  = janimarr[animnr]["timeeffect"].as<long>();
        ledsettings[lednr].anim[animnr].effect      = janimarr[animnr]["effect"].as<uint8_t>();
        regelcounter++; 
      }

    }

      msgAnswer = "Settings geladen voor " + String(regelcounter) + " ledanimaties";

  }
  Println(msgAnswer);
  return msgAnswer;
}
