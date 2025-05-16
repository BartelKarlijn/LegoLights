#pragma once
String  fileLoadLed(int lednr, String animatie) {
// Load LED settings for given animatie
  char filename[18];
  String msgAnswer;

  sprintf(filename, "/cfg_led%02d.ini", lednr);
  //sprintf(filename, "/a.txt", lednr);

  Print("Filename ");
  Println(String(filename));

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
    //JsonArray array = doc.as<JsonArray>();
    JsonObject objec = doc.as<JsonObject>();

    auto error = deserializeJson(doc, file_content);
    if ( error ) { 
      Println("Error interpreting config file");
      msgAnswer ="Error interpreting config file";
    }

    Println("gezochte anim=" + animatie);
    if(doc[animatie].isNull()) {
      Println(" animatie not found");
      msgAnswer = "Animatie not found";
    }
    else {
      
      ledsingle[lednr].desc = doc[animatie]["desc"].as<String>();
      ledsingle[lednr].bri = doc[animatie]["bri"].as<int>();
      ledsingle[lednr].timeon = doc[animatie]["timeon"].as<int>();
      ledsingle[lednr].timeoff = doc[animatie]["timeoff"].as<int>();
      ledsingle[lednr].timeeffect = doc[animatie]["timeeffect"].as<int>();
      ledsingle[lednr].effect = doc[animatie]["effect"].as<int>();
      ledsingle[lednr].image = doc[animatie]["image"].as<String>();
      ledsingle[lednr].animatie = doc[animatie]["animatie"].as<String>();
      
      msgAnswer = "Settings opgeladen voor led " + ledsingle[lednr].desc +", animatie " + animatie;

    }
  }

  return msgAnswer;
}
