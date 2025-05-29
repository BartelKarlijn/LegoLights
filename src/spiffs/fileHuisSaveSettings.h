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
      doc["animnr"][lednr] = huisSetting.animnrled[lednr];
    }
    for (int rgbnr = 0; rgbnr < RGB_NR_ITEMS; rgbnr++) {
      // Create a JsonObject for each RGB      
      doc["animnr"][rgbnr] = huisSetting.animnrrgb[rgbnr];
    }

    // Serialize the JSON and write it to the file
    serializeJson(doc, tmp);
    Println("Huissettings saved: " + tmp);

    writeFile(SPIFFS, filename, tmp);

    msgAnswer = "LED settings saved";
    return msgAnswer;
}
