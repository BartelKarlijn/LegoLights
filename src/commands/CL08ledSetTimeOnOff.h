void cL08ledSetTimeOnOff(){
    // Set On Off time to Led
    size_t lednr = commandParts.arg1.toInt();
    size_t tOn = commandParts.arg2.toInt();  //aparently toInt also converts to long
    size_t tOff = commandParts.arg3.toInt();
    Println("L08 Set led " + commandParts.arg1 + " timeOn= " + commandParts.arg2 + ", timeOff= " + commandParts.arg3);
    if (lednr >= 0 && lednr < LED_NR_ITEMS) {
        if ((tOn >= 0) && (tOff >= 0)) {
            ledactive[lednr].timeon = tOn;
            ledactive[lednr].timeoff = tOff;
        } else {
            Println("Invalid time value(s)");
        }
    } else {
        Println("Invalid led number");
    }
    return;
}
