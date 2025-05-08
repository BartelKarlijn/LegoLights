void cK01kringSetJpg(){
    // Set JPEG for Kring
    int kringnr = commandParts.arg1.toInt();
    String image = commandParts.arg2;
    if (kringnr >= 0 && kringnr < STRIP_NR_ITEMS) {
        // Check if the JPEG file exists in SPIFFS
        if (SPIFFS.exists("/" + image)) {
            // Set the JPEG for the specified Kring
            kring[kringnr].image = image;
            Serial.println("Kring " + String(kringnr) + " set to image: " + image);
        } else {
            Serial.println("Error: image file does not exist: " + image);
        }
    } else {
        Serial.println("Error: Invalid Kring number: " + String(kringnr));
    }
}
