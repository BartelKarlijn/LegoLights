void cL02ledSetName(){
    // Set name to Led
    size_t lednr = commandParts.arg1.toInt();
    Println("L02 Set name of " + commandParts.arg1 + " to " + commandParts.arg2);

    if (lednr >= 0 && lednr < LED_NR_ITEMS) {
        ledactive[lednr].desc = commandParts.arg2;
    } else {
        Println("Invalid led number");
    }
        
    return;
    
}
