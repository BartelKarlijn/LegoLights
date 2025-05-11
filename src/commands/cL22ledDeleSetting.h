void cL22ledDeleSetting(){
    // Load settings for a specific led
    int lednr = commandParts.arg1.toInt();
    String animatie = commandParts.arg2;

    if (lednr >= 0 && lednr < LED_NR_ITEMS) {
        String result = fileDeleteLed(lednr, animatie);
        Println(result);
        
    } else {
        Println("Error: Invalid Led number: " + String(lednr));
    }
}
