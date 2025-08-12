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
    doc["animnrhuis"] = huisSetting.animnrhuis;
    for (size_t i = 0; i < HUIS_NR_ANIM; i++) {
      // Create a JsonObject for each animation description
      doc["animdesc"][i] = huisSetting.animdesc[i];
    }
    
    // Serialize the JSON and write it to the file
    serializeJson(doc, tmp);
    Println("Huissettings saved: " + tmp);

    writeFile(SPIFFS, filename, tmp);

    msgAnswer = "Huis settings saved";
    return msgAnswer;
}
