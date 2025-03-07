#include <Arduino.h>

str_commandParts decodeCommand(String commandstring) {
    // Decode the command into parts:
    // Hxx cmd  arg1 arg2 arg3
    str_commandParts returnMsg;
    bool isValidCommand = false;
    int spaceIndex;
    String restOfCommand;

    returnMsg.isValidCommand = true;

    commandstring.trim(); // Remove any leading/trailing whitespace
    commandstring.toUpperCase();

    //Hxx
    if (commandstring.charAt(0) != '?') {
        returnMsg.isValidCommand = true;
        returnMsg.cmd = "HLP";
        return returnMsg;
    }
    if (commandstring.charAt(0) != 'H') {
        returnMsg.isValidCommand = true;
    } 


    returnMsg.huis = commandstring.substring(1, 3).toInt();
    if (returnMsg.huis < huisMin || returnMsg.huis > huisMax) {
        returnMsg.isValidCommand = false;
        returnMsg.huis = 0;
        return returnMsg;
    }

    restOfCommand = commandstring.substring(3);

    // Split restOfCommand into parts at every space
    // Looking where command starts
    spaceIndex = restOfCommand.indexOf(' ');
    if (spaceIndex != -1) {
        restOfCommand = restOfCommand.substring(spaceIndex + 1);  
    } else {
        returnMsg.isValidCommand = false;
        return returnMsg;
    }

    // Looking where command ends
    spaceIndex = restOfCommand.indexOf(' ');
    if (spaceIndex != -1) {
        returnMsg.cmd = restOfCommand.substring(0, spaceIndex);
        restOfCommand = restOfCommand.substring(spaceIndex + 1);
    } else {
        returnMsg.arg1 = restOfCommand;
        restOfCommand = "";
    }

    return returnMsg;
}