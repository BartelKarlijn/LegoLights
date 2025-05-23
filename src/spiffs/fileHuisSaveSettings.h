#pragma once
String fileHuisSaveSettings() {
    // Save all HUIS settings into a JSON file
    char filename[18] = FILE_HUIS;
    String msgAnswer;
    String tmp;

    Print("Filename ");
    Println(String(filename));

    JsonDocument doc; // Adjust size as needed

    doc["huisnr"] = huisSetting.huisnr;
    doc["desc"] = huisSetting.desc;
    doc["image"] = huisSetting.image;
    
    for (int lednr = 0; lednr < LED_NR_ITEMS; lednr++) {
      // Create a JsonObject for each LED      
      doc["animnr"][lednr] = huisSetting.animnr[lednr];
        //JsonArray animArray = doc.to<JsonArray>();
        //animArray.add(huisSetting.animnr[lednr]);
    }

    // Serialize the JSON and write it to the file
    serializeJson(doc, tmp);
    Println("Huissettings saved: " + tmp);

    writeFile(SPIFFS, filename, tmp);

    msgAnswer = "LED settings saved";
    return msgAnswer;
}
