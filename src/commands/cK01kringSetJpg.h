void cK01kringSetJpg(){
    // Set JPEG for Kring
    size_t rgbnr = commandParts.arg1.toInt();
    String image = commandParts.arg2;
    if (rgbnr >= 0 && rgbnr < RGB_NR_ITEMS) {
        // Check if the JPEG file exists in SPIFFS
        if (SPIFFS.exists("/" + image)) {
            // Set the JPEG for the specified Kring
            rgbactive[rgbnr].image = image;
            Println("Kring " + String(rgbnr) + " set to image: " + image);
        } else {
            Println("Error: image file does not exist: " + image);
        }
    } else {
        Println("Error: Invalid Kring number: " + String(rgbnr));
    }
}
