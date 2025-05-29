#pragma once
String fileRgbSaveSettings() {
    // Save all RGB settings into a JSON file
    char filename[18] = FILE_RGB;
    String msgAnswer;
    String tmp;

    Print("Filename ");
    Println(String(filename));

    JsonDocument doc; // Adjust size as needed
    JsonArray ledArr = doc.to<JsonArray>();
        
    for (int lednr = 0; lednr < LED_NR_ITEMS; lednr++) {
        // Create a JsonObject for each LED
        JsonObject ledLine = ledArr.add<JsonObject>();
        ledLine["lednr"] = lednr;
        ledLine["leddesc"] = ledsettings[lednr].leddesc;
        ledLine["ledimage"] = ledsettings[lednr].ledimage;

        JsonDocument animDoc;
        JsonArray animArr = animDoc.to<JsonArray>();
        for (size_t animnr = 0; animnr < LED_NR_ANIM; animnr++){
          JsonObject animLine = animArr.add<JsonObject>();
          animLine["animdesc"]   = ledsettings[lednr].anim[animnr].animdesc;
          animLine["bri"]        = ledsettings[lednr].anim[animnr].bri;
          animLine["timeon"]     = ledsettings[lednr].anim[animnr].timeon;
          animLine["timeoff"]    = ledsettings[lednr].anim[animnr].timeoff;
          animLine["timeeffect"] = ledsettings[lednr].anim[animnr].timeeffect;
          animLine["effect"]     = ledsettings[lednr].anim[animnr].effect;
        }
        serializeJson(animDoc, tmp);

        ledLine["anim"] = tmp;
        
    }

    // Serialize the JSON and write it to the file
    serializeJsonPretty(doc, tmp);

    writeFile(SPIFFS, filename, tmp);

    msgAnswer = "LED settings saved";
    return msgAnswer;
}
