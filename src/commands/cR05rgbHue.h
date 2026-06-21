void cR05rgbHue(){
    // Set HUE for rgb
    uint8_t rgbnr = commandParts.arg1.toInt();
    uint8_t nr = commandParts.arg2.toInt();
    uint8_t hue = commandParts.arg3.toInt();
    if (rgbnr >= 0 && rgbnr < RGB_NR_ITEMS) {
        switch (nr) {
            case 1:
                rgbactive[rgbnr].hue1 = hue;
                break;
            case 2:
                rgbactive[rgbnr].hue2 = hue;
                break;
            case 3:
                rgbactive[rgbnr].hue3 = hue;
                break;
            case 4:
                rgbactive[rgbnr].hue4 = hue;
                break;
            default:
                Println("Error: Invalid hue number: " + String(nr));
        }       
    } else {
        Println("Error: Invalid rgb number: " + String(rgbnr));
    }
}
