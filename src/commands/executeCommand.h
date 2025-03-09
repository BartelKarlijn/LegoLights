void executeCommand() {
    for (int i = 0; i < sizeof(validCommands); i++) {
        if (commandParts.cmd == validCommands[i].cmd) {
            validCommands[i].function();
            return;
        }
    }
}
