void cK21kringLoadSetting(){
    // load settings for a specific Kring
    int kringnr = commandParts.arg1.toInt();

    if (kringnr >= 0 && kringnr < STRIP_NR_ITEMS) {
        String result = fileLoad2Kring(kringnr);
        Println(result);
        
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }}
