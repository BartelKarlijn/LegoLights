void executeCommand() {
    // Eerst checken of commando voor dit huisje is.
    if (commandParts.huis != huisSetting.huisnr) {
        return;
    }

    // dan commando uitvoeren
    for (size_t i = 0; i < sizeof(validCommands); i++) {
        if (commandParts.cmd == validCommands[i].cmd) {
            Println("cmd" + validCommands[i].cmd);
            validCommands[i].function();
            return;
        }
    }
    Println("Invalid cmd"+ commandParts.cmd);
}
