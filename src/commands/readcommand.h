void readcommand() {
    if (Serial.available() > 0) {
        String command = Serial.readStringUntil('\n'); // Read the command until a newline character
        command.trim(); // Remove any leading/trailing whitespace
//        executeCommand(command); // Execute the command
    }
}
