str_commandParts decodeCommandPart (String commandstring) {
    // Decode the beginning of command into parts:
    // eg H01      : command = H, commandnr = 1, argument = _, restOfCommand = "xxx"
    // eg W01 ssid : command = W, commandnr = 1, argument = ssid, restOfCommand = "xxx"
    str_commandParts returnMsg;
    int spaceIndex;
    returnMsg.command = commandstring.charAt(0);
    // check if command is valid
    for (char validChar : validChars) {
        if (returnMsg.command == validChar) {
            returnMsg.isValidCommand = true;
            break;
        }
    }
    if (returnMsg.isValidCommand) {
        spaceIndex = commandstring.indexOf(' ');
        if (spaceIndex > 0) {
            returnMsg.commandnr = commandstring.substring(1, spaceIndex).toInt();
            returnMsg.restOfCommand = commandstring.substring(spaceIndex+1, 100);
        } else {
            returnMsg.commandnr = commandstring.substring(1).toInt();
            returnMsg.argument = "";
        }
    } else {
        // command is not valid
        returnMsg.commandnr = 0;
        returnMsg.argument = "";
        returnMsg.restOfCommand = "";
    }
    Print("x Command: "); Println(commandstring);
    Print("x CommandParts.comm: "); Println(returnMsg.command);
    Print("x CommandParts.nr  : "); Println(returnMsg.commandnr);
    Print("x CommandParts.arg : "); Println(returnMsg.argument);
    Print("x CommandParts.rest: "); Println(returnMsg.restOfCommand);
    
    return returnMsg;    
}