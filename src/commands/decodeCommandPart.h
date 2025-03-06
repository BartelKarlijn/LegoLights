#include <Arduino.h>
#include <vector>
#include "config_commands.h"

str_commandParts decodeCommandPart(String commandstring) {
    // Decode the command into parts:
    // Hxx cmd  arg1 arg2 arg3
    str_commandParts returnMsg;
    bool isValidCommand = false;
    int spaceIndex;
    String restOfCommand;

    returnMsg.isValidCommand = true;

    //Hxx
    if (commandstring.charAt(0) != 'H') {
        returnMsg.isValidCommand = false;
    }

    returnMsg.huis = commandstring.substring(1, 3).toInt();
    if (returnMsg.huis < huisMin || returnMsg.huis > huisMax) {
        returnMsg.isValidCommand = false;
        returnMsg.huis = 0;
    }

    restOfCommand = commandstring.substring(3);

    // Split restOfCommand into parts at every space
    spaceIndex = restOfCommand.indexOf(' ');
    if (spaceIndex != -1) {
        returnMsg.cmd = restOfCommand.substring(0, spaceIndex);
        restOfCommand = restOfCommand.substring(spaceIndex + 1);
    } else {
        returnMsg.cmd = restOfCommand;
        restOfCommand = "";
    }

    spaceIndex = restOfCommand.indexOf(' ');
    if (spaceIndex != -1) {
        returnMsg.arg1 = restOfCommand.substring(0, spaceIndex);
        restOfCommand = restOfCommand.substring(spaceIndex + 1);
    } else {
        returnMsg.arg1 = restOfCommand;
        restOfCommand = "";
    }

    spaceIndex = restOfCommand.indexOf(' ');
    if (spaceIndex != -1) {
        returnMsg.arg2 = restOfCommand.substring(0, spaceIndex);
        restOfCommand = restOfCommand.substring(spaceIndex + 1);
    } else {
        returnMsg.arg2 = restOfCommand;
        restOfCommand = "";
    }

    returnMsg.arg3 = restOfCommand;

    return returnMsg;
}