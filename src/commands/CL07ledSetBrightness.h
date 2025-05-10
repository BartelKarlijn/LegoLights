void cL07ledSetBrightness(){
    // Set brightness to Led
    int lednr = commandParts.arg1.toInt();
    int bri = commandParts.arg2.toInt();

    Println("L02 Set brightness of " + commandParts.arg1 + " to " + commandParts.arg2);
    if (lednr >= 0 && lednr < LED_NR_ITEMS) {
        if (bri >= 0 && bri <= 4095) {
            ledsingle[lednr].bri = bri;
        } else {
            Println("Invalid brightness value");
        }
    } else {
        Println("Invalid led number");
    }
    return;
}
