void cR03rgbStartStop(){
    // Set Start Stop led for rgb
    uint8_t rgbnr = commandParts.arg1.toInt();
    uint8_t start = commandParts.arg2.toInt();
    uint8_t stop = commandParts.arg3.toInt();
    if (rgbnr >= 0 && rgbnr < RGB_NR_ITEMS) {
        rgbactive[rgbnr].startrgb = start;
        rgbactive[rgbnr].stoprgb = stop;
    } else {
        Println("Error: Invalid rgb number: " + String(rgbnr));
    }
}
