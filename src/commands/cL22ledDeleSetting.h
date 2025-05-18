void cL22ledDeleSetting(){
    // Load settings for a specific led
    int lednr = commandParts.arg1.toInt();
    int animnr = commandParts.arg2.toInt();

    if (lednr >= 0 && lednr < LED_NR_ITEMS) {
        settingLedDelete(lednr, animnr);
    } else {
        Println("Error: Invalid Led number: " + String(lednr));
    }
}
