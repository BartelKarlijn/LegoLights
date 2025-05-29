void cK20kringSaveSetting(){
    // Save settings for a specific Kring
    int kringnr = commandParts.arg1.toInt();

    if (kringnr >= 0 && kringnr < RGB_NR_ITEMS) {
        String result = fileSaveKring(kringnr);
        Println(result);
        
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }
}
