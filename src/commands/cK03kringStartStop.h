void cK03kringStartStop(){
    // Set Start Stop led for Kring
    size_t rgbnr = commandParts.arg1.toInt();
    size_t start = commandParts.arg2.toInt();
    size_t stop = commandParts.arg3.toInt();
    if (rgbnr >= 0 && rgbnr < RGB_NR_ITEMS) {
        rgbactive[rgbnr].startrgb = start;
        rgbactive[rgbnr].stoprgb = stop;
    } else {
        Println("Error: Invalid Kring number: " + String(rgbnr));
    }
}
