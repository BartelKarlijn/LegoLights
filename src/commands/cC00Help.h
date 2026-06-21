void cC00Help(){
    // Show Commands
    for (uint8_t i = 0; i < 30 ; i++) {
        Print(validCommands[i].cmd + " ");
        Print(validCommands[i].arguments + " ");
        Println(validCommands[i].desc);
    }

}
