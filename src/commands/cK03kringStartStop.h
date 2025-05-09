void cK03kringStartStop(){
    // Set Start Stop led for Kring
    int kringnr = commandParts.arg1.toInt();
    int start = commandParts.arg2.toInt();
    int stop = commandParts.arg3.toInt();
    if (kringnr >= 0 && kringnr < STRIP_NR_ITEMS) {
        kring[kringnr].startled = start;
        kring[kringnr].stopled = stop;
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }
}
