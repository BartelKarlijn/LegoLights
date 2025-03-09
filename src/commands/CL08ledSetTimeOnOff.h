void CL08ledSetTimeOnOff(){
    // Set On Off time to Led
    int lednr = commandParts.arg1.toInt();
    int tOn = commandParts.arg2.toInt();  //aparently toInt also converts to long
    int tOff = commandParts.arg3.toInt();
    if (commandParts.isValidCommand){ 
        Println("L02 Set led " + commandParts.arg1 + " timeOn= " + commandParts.arg2 + ", timeOff= " + commandParts.arg3);
        if (lednr >= 0 && lednr < LED_NR_ITEMS) {
            if ((tOn >= 0) && (tOff >= 0)) {
                ledsingle[lednr].timeon = tOn;
                ledsingle[lednr].timeoff = tOff;
            } else {
                Println("Invalid time value(s)");
            }
        } else {
            Println("Invalid led number");
        }
        return;
    }
}
