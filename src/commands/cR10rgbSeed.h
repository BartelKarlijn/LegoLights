void cR10rgbSeed(){
    // Set JPEG for rgb
    uint8_t rgbnr = commandParts.arg1.toInt();
    uint8_t seed = commandParts.arg2.toInt();
    if (rgbnr >= 0 && rgbnr < RGB_NR_ITEMS) {
        rgbactive[rgbnr].seed = seed;
    } else {
        Println("Error: Invalid rgb number: " + String(rgbnr));
    }
}
