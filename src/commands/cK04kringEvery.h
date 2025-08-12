void cK04kringEvery(){
    // Set Every for Kring
    size_t rgbnr = commandParts.arg1.toInt();
    size_t every = commandParts.arg2.toInt();
    if (rgbnr >= 0 && rgbnr < RGB_NR_ITEMS) {
        rgbactive[rgbnr].every = every;
    } else {
        Println("Error: Invalid Kring number: " + String(rgbnr));
    }
}
