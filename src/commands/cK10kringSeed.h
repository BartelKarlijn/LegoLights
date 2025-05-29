void cK10kringSeed(){
    // Set JPEG for Kring
    int kringnr = commandParts.arg1.toInt();
    int seed = commandParts.arg2.toInt();
    if (kringnr >= 0 && kringnr < RGB_NR_ITEMS) {
        kring[kringnr].seed = seed;
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }
}
