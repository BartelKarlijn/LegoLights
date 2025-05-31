void cK08kringTonToff(){
    // Set effect and time effect for Kring
    size_t kringnr = commandParts.arg1.toInt();
    size_t effect = commandParts.arg2.toInt();
    unsigned long timeeffect = commandParts.arg3.toDouble();
    if (kringnr >= 0 && kringnr < RGB_NR_ITEMS) {
        kring[kringnr].effect = effect;
        kring[kringnr].timeeffect = timeeffect;
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }
}
