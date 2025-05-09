void cK09kringEffect(){
    // Set JPEG for Kring
    int kringnr = commandParts.arg1.toInt();
    String name = commandParts.arg2;
    if (kringnr >= 0 && kringnr < STRIP_NR_ITEMS) {
        kring[kringnr].desc = name;
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }
}
