#pragma once
String  fileDeleteLed(int lednr, String animatie) {
// Delete one animation from the file
char filename[18];
String msgAnswer;
JsonDocument doc;

String key;

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

  //bestaande file inlezen
  auto error = deserializeJson(doc, file_content);
  if ( error ) { 
    Println("Error interpreting config file");
    msgAnswer ="Error interpreting config file";
  }
  else {
    // de entry verwijderen:
    if (doc.containsKey(animatie)) {
      doc.remove(animatie);
      Println("Verwijderen van " + animatie);
    }
    else {
      Println("Geen entry gevonden voor " + animatie);
    }
  }

  // write config file
    String tmp = "";
    serializeJson(doc, tmp);
    writeFile(SPIFFS, filename, tmp);
  }
  Println(fileListLed(lednr));

  return "Settings bewaard voor " + ledsingle[lednr].desc;
}