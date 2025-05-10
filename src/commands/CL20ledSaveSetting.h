void cL20ledSaveSetting(){
    // Save settings for a specific Kring
    int lednr = commandParts.arg1.toInt();
    String animatie = commandParts.arg2;

    if (lednr >= 0 && lednr < LED_NR_ITEMS) {
        String result = fileSaveLed(lednr, animatie);
        Println(result);
        
    } else {
        Println("Error: Invalid Led number: " + String(lednr));
    }
}
