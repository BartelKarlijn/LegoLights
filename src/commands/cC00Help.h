void cC00Help(){
    // Show Commands
//    for (int i = 0; i < sizeof(validCommands) ; i++) {
    for (int i = 0; i < 30 ; i++) {
        Print(validCommands[i].cmd + " ");
        Print(validCommands[i].arguments + " ");
        Println(validCommands[i].desc);
    }

}
