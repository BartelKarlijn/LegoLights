void cR02rgbSetName(){
    // Set DESC for rgb
    uint8_t rgbnr = commandParts.arg1.toInt();
    String name = commandParts.arg2;
    if (rgbnr >= 0 && rgbnr < RGB_NR_ITEMS) {
        rgbactive[rgbnr].desc = name;
    } else {
        Println("Error: Invalid rgb number: " + String(rgbnr));
    }
}
