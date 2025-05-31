void cK04kringEvery(){
    // Set Every for Kring
    size_t kringnr = commandParts.arg1.toInt();
    size_t every = commandParts.arg2.toInt();
    if (kringnr >= 0 && kringnr < RGB_NR_ITEMS) {
        kring[kringnr].every = every;
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }
}
