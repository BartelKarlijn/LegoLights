void cR08rgbTonToff(){
    // Set effect and time effect for rgb
    size_t rgbnr = commandParts.arg1.toInt();
    size_t effect = commandParts.arg2.toInt();
    unsigned long timeeffect = commandParts.arg3.toDouble();
    if (rgbnr >= 0 && rgbnr < RGB_NR_ITEMS) {
        rgbactive[rgbnr].effect = effect;
        rgbactive[rgbnr].timeeffect = timeeffect;
    } else {
        Println("Error: Invalid rgb number: " + String(rgbnr));
    }
}
