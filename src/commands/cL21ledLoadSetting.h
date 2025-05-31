void cL21ledLoadSetting(){
    // Load settings for a specific led
    size_t lednr = commandParts.arg1.toInt();
    String animatie = commandParts.arg2;

    if (lednr >= 0 && lednr < LED_NR_ITEMS) {
        String result = fileLedLoadSettings();
        Println(result);
        
    } else {
        Println("Error: Invalid Led number: " + String(lednr));
    }
}
