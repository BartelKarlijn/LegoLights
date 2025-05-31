void cK01kringSetJpg(){
    // Set JPEG for Kring
    size_t kringnr = commandParts.arg1.toInt();
    String image = commandParts.arg2;
    if (kringnr >= 0 && kringnr < RGB_NR_ITEMS) {
        // Check if the JPEG file exists in SPIFFS
        if (SPIFFS.exists("/" + image)) {
            // Set the JPEG for the specified Kring
            kring[kringnr].image = image;
            Println("Kring " + String(kringnr) + " set to image: " + image);
        } else {
            Println("Error: image file does not exist: " + image);
        }
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }
}
