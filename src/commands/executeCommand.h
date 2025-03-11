void executeCommand() {
    // Eerst checken of commando voor dit huisje is.
    Println("Huis = " + String(commandParts.huis) + " cmd = " + commandParts.cmd + " arg1 = " + commandParts.arg1 + " arg2 = " + commandParts.arg2 + " arg3 = " + commandParts.arg3);
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
