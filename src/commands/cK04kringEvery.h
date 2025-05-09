void cK04kringEvery(){
    // Set Every for Kring
    int kringnr = commandParts.arg1.toInt();
    int every = commandParts.arg2.toInt();
    if (kringnr >= 0 && kringnr < STRIP_NR_ITEMS) {
        kring[kringnr].every = every;
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }
}
