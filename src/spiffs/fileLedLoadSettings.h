#pragma once
String  fileLedLoadSettings() {
// Load all Led settings into memory
  char filename[18]= "/cfg_led.ini";
  String msgAnswer;

  Print("Filename ");
  Println(String(filename));

  if (!SPIFFS.exists(filename)) {
    msgAnswer = "File does not exist, creating default one";
    Println("TODO TODO TODO");
    for(int lednr=0; lednr<LED_NR_ITEMS; lednr++) {
      ledsettings[lednr].leddesc          = LED_SINGLEDEFAULT.desc + String(lednr);
      ledsettings[lednr].ledimage         = LED_SINGLEDEFAULT.image;
      ledsettings[lednr].anim[0].animdesc = LED_SINGLEDEFAULT.animatie;
      ledsettings[lednr].anim[0].bri      = LED_SINGLEDEFAULT.bri;
      ledsettings[lednr].anim[0].timeon   = LED_SINGLEDEFAULT.timeon;
      ledsettings[lednr].anim[0].timeoff  = LED_SINGLEDEFAULT.timeoff;
      ledsettings[lednr].anim[0].timeeffect = LED_SINGLEDEFAULT.timeeffect;
      ledsettings[lednr].anim[0].effect   = LED_SINGLEDEFAULT.effect;
    }

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
      msgAnswer ="Error interpreting config file";
    }

    int regelcounter = 0;
    for (JsonPair ledkv : doc.as<JsonObject>()) {
      String ledkey = ledkv.key().c_str();
      int lednr = ledkey.toInt();
      JsonObject ledvalue = ledkv.value();
      
      ledsettings[lednr].leddesc = ledvalue["leddesc"].as<String>();
      ledsettings[lednr].ledimage = ledvalue["ledimage"].as<String>();
      JsonDocument janim = ledvalue["anim"].as<JsonObject>();

      for (JsonPair animkv : janim.as<JsonObject>()) {
        String animkey = animkv.key().c_str();
        int animnr = animkey.toInt();
        JsonObject animvalue = animkv.value();
        ledsettings[lednr].anim[animnr].animdesc = animvalue["animdesc"].as<String>();
        ledsettings[lednr].anim[animnr].bri = animvalue["bri"].as<int>();
        ledsettings[lednr].anim[animnr].timeon = animvalue["timeon"].as<int>();
        ledsettings[lednr].anim[animnr].timeoff = animvalue["timeoff"].as<int>();
        ledsettings[lednr].anim[animnr].timeeffect = animvalue["timeeffect"].as<int>();
        ledsettings[lednr].anim[animnr].effect = animvalue["effect"].as<int>();
        regelcounter++;
      }
      
    }
    msgAnswer = "Settings geladen voor " + String(regelcounter) + " ledanimaties";

  }
  Println(msgAnswer);
  return msgAnswer;
}
