#pragma once
String fileLedSaveSettings() {
    // Save all LED settings into a JSON file
    char filename[18] = "/cfg_ledsave.ini";
    String msgAnswer;

    Print("Filename ");
    Println(String(filename));

    JsonDocument doc; // Adjust size as needed
    JsonArray ledArray = doc.to<JsonArray>(); // Create the root array
//    JsonArray animArray = ledArray["anim"].to<JsonArray>(); // Create the nested array for animations

    for (int lednr = 0; lednr < LED_NR_ITEMS; lednr++) {
        // Create a JsonObject for each LED
        JsonObject ledObj = ledArray.createNestedObject();
        ledObj["lednr"] = lednr;
        ledObj["leddesc"] = ledsettings[lednr].leddesc;
        ledObj["ledimage"] = ledsettings[lednr].ledimage;

  /*      // Create a JsonArray for animations
        JsonArray animArray = ledObj.createNestedArray("anim");
        for (int animnr = 0; animnr < LED_NR_ANIM; animnr++) {
            JsonObject animObj = animArray.createNestedObject();
            animObj["animdesc"] = ledsettings[lednr].anim[animnr].animdesc;
            animObj["bri"] = ledsettings[lednr].anim[animnr].bri;
            animObj["timeon"] = ledsettings[lednr].anim[animnr].timeon;
            animObj["timeoff"] = ledsettings[lednr].anim[animnr].timeoff;
            animObj["timeeffect"] = ledsettings[lednr].anim[animnr].timeeffect;
            animObj["effect"] = ledsettings[lednr].anim[animnr].effect;
        }
    */
    }

    // Serialize the JSON and write it to the file
    String tmp;
    serializeJson(doc, tmp);
    writeFile(SPIFFS, filename, tmp);

    msgAnswer = "LED settings saved";
    Println(tmp); // Debug: Print the JSON content
    return msgAnswer;
}
