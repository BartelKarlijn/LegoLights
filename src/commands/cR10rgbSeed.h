void cR10rgbSeed(){
    // Set JPEG for rgb
    size_t rgbnr = commandParts.arg1.toInt();
    size_t seed = commandParts.arg2.toInt();
    if (rgbnr >= 0 && rgbnr < RGB_NR_ITEMS) {
        rgbactive[rgbnr].seed = seed;
    } else {
        Println("Error: Invalid rgb number: " + String(rgbnr));
    }
}
