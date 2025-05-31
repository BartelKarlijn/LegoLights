void cK03kringStartStop(){
    // Set Start Stop led for Kring
    size_t kringnr = commandParts.arg1.toInt();
    size_t start = commandParts.arg2.toInt();
    size_t stop = commandParts.arg3.toInt();
    if (kringnr >= 0 && kringnr < RGB_NR_ITEMS) {
        kring[kringnr].startrgb = start;
        kring[kringnr].stoprgb = stop;
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }
}
