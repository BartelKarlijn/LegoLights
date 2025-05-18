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

    JsonDocument doc;

    auto error = deserializeJson(doc, file_content);
    if ( error ) { 
      msgAnswer ="Error interpreting config file";
    }

    int regelcounter = 0;
    JsonArray jledarr = doc.as<JsonArray>();
    Println("aantal leds: " + String(jledarr.size()));
    for (int lednr=0; lednr<jledarr.size(); lednr++) {
      ledsettings[lednr].leddesc          = jledarr[lednr]["leddesc"].as<String>();
      ledsettings[lednr].ledimage         = jledarr[lednr]["ledimage"].as<String>();
      Print(String(lednr)+" desc: " + jledarr[lednr]["leddesc"].as<String>());

      JsonArray janimarr = jledarr[lednr]["anim"].as<JsonArray>();
      Println(" aantal anims: " + String(janimarr.size()));
      for (int animnr=0; animnr<janimarr.size(); animnr++) {
        ledsettings[lednr].anim[animnr].animdesc    = janimarr[animnr]["animdesc"].as<String>();
        ledsettings[lednr].anim[animnr].bri         = janimarr[animnr]["bri"].as<int>();
        ledsettings[lednr].anim[animnr].timeon      = janimarr[animnr]["timeon"].as<int>();
        ledsettings[lednr].anim[animnr].timeoff     = janimarr[animnr]["timeoff"].as<int>();
        ledsettings[lednr].anim[animnr].timeeffect  = janimarr[animnr]["timeeffect"].as<int>();
        ledsettings[lednr].anim[animnr].effect      = janimarr[animnr]["effect"].as<int>();
        regelcounter++; 
      }

    }

      msgAnswer = "Settings geladen voor " + String(regelcounter) + " ledanimaties";

  }
  Println(msgAnswer);
  return msgAnswer;
}
