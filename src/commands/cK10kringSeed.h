void cK10kringSeed(){
    // Set JPEG for Kring
    size_t rgbnr = commandParts.arg1.toInt();
    size_t seed = commandParts.arg2.toInt();
    if (rgbnr >= 0 && rgbnr < RGB_NR_ITEMS) {
        rgbactive[rgbnr].seed = seed;
    } else {
        Println("Error: Invalid Kring number: " + String(rgbnr));
    }
}
