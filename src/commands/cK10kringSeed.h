void cK10kringSeed(){
    // Set JPEG for Kring
    size_t kringnr = commandParts.arg1.toInt();
    size_t seed = commandParts.arg2.toInt();
    if (kringnr >= 0 && kringnr < RGB_NR_ITEMS) {
        kring[kringnr].seed = seed;
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }
}
