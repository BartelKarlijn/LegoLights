void executeCommand() {
    // Eerst checken of commando voor dit huisje is.
    if (commandParts.huis != huis.huisnr) {
        return;
    }

    // dan commando uitvoeren
    for (int i = 0; i < sizeof(validCommands); i++) {
        if (commandParts.cmd == validCommands[i].cmd) {
            validCommands[i].function();
            return;
        }
    }
}
