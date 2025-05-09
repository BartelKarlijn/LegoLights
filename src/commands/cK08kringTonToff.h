void cK08kringTonToff(){
    // Set effect and time effect for Kring
    int kringnr = commandParts.arg1.toInt();
    int effect = commandParts.arg2.toInt();
    unsigned long timeeffect = commandParts.arg3.toDouble();
    if (kringnr >= 0 && kringnr < STRIP_NR_ITEMS) {
        kring[kringnr].effect = effect;
        kring[kringnr].timeeffect = timeeffect;
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }
}
