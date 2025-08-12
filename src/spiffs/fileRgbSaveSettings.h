#pragma once
String fileRgbSaveSettings() {
    // Save all RGB settings into a JSON file
    char filename[18] = FILE_RGB;
    String msgAnswer;
    String tmp;

    Print("Filename ");
    Println(String(filename));

    JsonDocument doc; // Adjust size as needed
    JsonArray rgbArr = doc.to<JsonArray>();
        
    for (size_t rgbnr = 0; rgbnr < RGB_NR_ITEMS; rgbnr++) {
        // Create a JsonObject for each RGB
        JsonObject rgbLine = rgbArr.add<JsonObject>();
        rgbLine["rgbnr"] = rgbnr;
        rgbLine["rgbdesc"] = rgbsettings[rgbnr].rgbdesc;
        rgbLine["rgbimage"] = rgbsettings[rgbnr].rgbimage;
        rgbLine["startrgb"] = rgbsettings[rgbnr].startrgb;
        rgbLine["stoprgb"] = rgbsettings[rgbnr].stoprgb;

        JsonDocument animDoc;
        JsonArray animArr = animDoc.to<JsonArray>();
        for (size_t animnr = 0; animnr < RGB_NR_ANIM; animnr++){
          JsonObject animLine = animArr.add<JsonObject>();
          animLine["hue1"]       = rgbsettings[rgbnr].anim[animnr].hue1;
          animLine["sat1"]       = rgbsettings[rgbnr].anim[animnr].sat1;
          animLine["bri1"]       = rgbsettings[rgbnr].anim[animnr].bri1;
          animLine["hue2"]       = rgbsettings[rgbnr].anim[animnr].hue2;
          animLine["sat2"]       = rgbsettings[rgbnr].anim[animnr].sat2;
          animLine["bri2"]       = rgbsettings[rgbnr].anim[animnr].bri2;
          animLine["hue3"]       = rgbsettings[rgbnr].anim[animnr].hue3;
          animLine["sat3"]       = rgbsettings[rgbnr].anim[animnr].sat3;
          animLine["bri3"]       = rgbsettings[rgbnr].anim[animnr].bri3;
          animLine["hue4"]       = rgbsettings[rgbnr].anim[animnr].hue4;
          animLine["sat4"]       = rgbsettings[rgbnr].anim[animnr].sat4;
          animLine["bri4"]       = rgbsettings[rgbnr].anim[animnr].bri4;
          animLine["every"]      = rgbsettings[rgbnr].anim[animnr].every;
          animLine["timeon"]     = rgbsettings[rgbnr].anim[animnr].timeon;
          animLine["timeoff"]    = rgbsettings[rgbnr].anim[animnr].timeoff;
          animLine["timeeffect"] = rgbsettings[rgbnr].anim[animnr].timeeffect;
          animLine["seed"]       = rgbsettings[rgbnr].anim[animnr].seed;
          animLine["effect"]     = rgbsettings[rgbnr].anim[animnr].effect;
        }

        rgbLine["anim"] = animDoc.as<JsonArray>();
    }

    // Serialize the JSON and write it to the file
    serializeJsonPretty(doc, tmp);

    writeFile(SPIFFS, filename, tmp);

    msgAnswer = "RGB settings saved";
    return msgAnswer;
}
