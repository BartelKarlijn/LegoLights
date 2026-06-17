void cR07rgbBri(){
    // Set BRI for rgb
    size_t rgbnr = commandParts.arg1.toInt();
    size_t nr = commandParts.arg2.toInt();
    size_t bri = commandParts.arg3.toInt();
    if (rgbnr >= 0 && rgbnr < RGB_NR_ITEMS) {
        switch (nr) {
            case 1:
                rgbactive[rgbnr].bri1 = bri;
                break;
            case 2:
                rgbactive[rgbnr].bri2 = bri;
                break;
            case 3:
                rgbactive[rgbnr].bri3 = bri;
                break;
            case 4:
                rgbactive[rgbnr].bri4 = bri;
                break;
            default:
                Println("Error: Invalid bri number: " + String(nr));
        }       
    } else {
        Println("Error: Invalid rgb number: " + String(rgbnr));
    }

}
