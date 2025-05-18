#pragma once
String fileLedListAnim(int lednr) {
  // List the animations in the file for a led
  char filename[18];
  String msgAnswer;

  sprintf(filename, "/cfg_led%02d.ini", lednr);

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
    else {
      Println("doclengte: " + String(doc.size()));
      
      for (JsonPair kv : doc.as<JsonObject>()) {
        Print("Key: ");
        Print(kv.key().c_str());
        msgAnswer += "<option value='";
        msgAnswer += kv.key().c_str();
        msgAnswer += "'>";
      }
    }
  }

   return msgAnswer;
}