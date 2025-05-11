#pragma once
String  fileLoadLed(int lednr, String animatie) {
// Save Led settings to file
  char filename[18];
  String msgAnswer;

  //sprintf(filename, "/cfg_led%02d.ini", lednr);
  sprintf(filename, "/a.txt", lednr);

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
      Println(doc[animatie].as<String>());
      Print("Desc: ");
      Println(doc[animatie]["desc"].as<String>());
      Print("Bri: ");
      Println(doc[animatie]["bri"].as<int>());
      Print("Timeon: ");
      Println(doc[animatie]["timeon"].as<int>());
      Print("Timeoff: ");
      Println(doc[animatie]["timeoff"].as<int>());
      Print("Timeeffect: ");
      Println(doc[animatie]["timeeffect"].as<int>());
      Print("Effect: ");
      Println(doc[animatie]["effect"].as<int>());

      Println("doclengte: " + String(doc.size()));
      
      for (JsonPair kv : doc.as<JsonObject>()) {
        Print("Key: ");
        Print(kv.key().c_str());
        Print(" Value: ");
        Println(kv.value().as<String>());
      }

      msgAnswer = "Settings opgeladen voor led " + ledsingle[lednr].desc;

    }
  }

   return msgAnswer;
}
