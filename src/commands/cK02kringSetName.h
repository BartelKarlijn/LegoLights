void cK02kringSetName(){
    // Set DESC for Kring
    int kringnr = commandParts.arg1.toInt();
    String name = commandParts.arg2;
    if (kringnr >= 0 && kringnr < RGB_NR_ITEMS) {
        kring[kringnr].desc = name;
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }
}
