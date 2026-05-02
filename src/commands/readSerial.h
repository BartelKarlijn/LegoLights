void readSerial() {
    if (Serial.available() > 0) {
        String commandstring = Serial.readStringUntil('\n'); // Read the command until a newline character
        // check structure of command: 
        //Println("Serialstring: " + commandstring);
        commandParts = decodeCommand(commandstring);
        executeCommand();

    }

    if (Serial1.available() > 0) {
        String commandstring = Serial1.readStringUntil('\n'); // Read the command until a newline character
        // check structure of command: 
        //Println("Serial1string: " + commandstring);
        commandParts = decodeCommand(commandstring);
        executeCommand();
    }
}
