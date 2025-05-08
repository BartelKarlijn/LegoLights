void CL02ledSetName(){
    // Set name to Led
    int lednr = commandParts.arg1.toInt();
    Println("L02 Set name of " + commandParts.arg1 + " to " + commandParts.arg2);

    if (lednr >= 0 && lednr < LED_NR_ITEMS) {
        ledsingle[lednr].desc = commandParts.arg2;
    } else {
        Println("Invalid led number");
    }
        
    return;
    
}
