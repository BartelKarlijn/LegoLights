void executeCommand() {
    // Eerst checken of commando voor dit huisje is.
    Println("checken of cmdhuis " + String(commandParts.huis) + " = huisnr" + String(huis.huisnr));
    if (commandParts.huis != huis.huisnr) {
        return;
    }
    Println("huis gevonden");

    // dan commando uitvoeren
    for (int i = 0; i < sizeof(validCommands); i++) {
        if (commandParts.cmd == validCommands[i].cmd) {
            Println("cmd" + validCommands[i].cmd);
            validCommands[i].function();
            return;
        }
    }
    Println("Invalid cmd"+ commandParts.cmd);
}
