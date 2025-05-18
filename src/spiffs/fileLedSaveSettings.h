#pragma once
String fileLedSaveSettings() {
    // Save all LED settings into a JSON file
    char filename[18] = "/cfg_ledsave.ini";
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


    }

    // Serialize the JSON and write it to the file
    serializeJson(doc, tmp);
    writeFile(SPIFFS, filename, tmp);

    msgAnswer = "LED settings saved";
    Println(tmp); // Debug: Print the JSON content
    return msgAnswer;
}
