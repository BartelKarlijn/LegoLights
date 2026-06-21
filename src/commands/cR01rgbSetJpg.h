void cR01rgbSetJpg(){
    // Set JPEG for rgb
    uint8_t rgbnr = commandParts.arg1.toInt();
    String image = commandParts.arg2;
    if (rgbnr >= 0 && rgbnr < RGB_NR_ITEMS) {
        // Check if the JPEG file exists in SPIFFS
        if (SPIFFS.exists("/" + image)) {
            // Set the JPEG for the specified rgb
            rgbactive[rgbnr].image = image;
            Println("rgb " + String(rgbnr) + " set to image: " + image);
        } else {
            Println("Error: image file does not exist: " + image);
        }
    } else {
        Println("Error: Invalid rgb number: " + String(rgbnr));
    }
}
