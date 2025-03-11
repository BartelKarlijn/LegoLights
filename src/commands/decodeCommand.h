#include <Arduino.h>

String decodeRestOfCommand (){
    // decode one part of the commandstring and returt the rest
    // restOfCommand is a global variable
    String returnArg;
    int spaceIndex;

    // Looking where command starts
    restOfCommand.trim();
    if (restOfCommand.length() == 0) {
        returnArg = "";
        return returnArg;
    }

    spaceIndex = restOfCommand.indexOf(' ');
    if (spaceIndex == -1) {
        // no spaces at end
        returnArg = restOfCommand;
        restOfCommand = "";  
    } else {
        returnArg = restOfCommand.substring(0, spaceIndex);
        restOfCommand = restOfCommand.substring(spaceIndex + 1);
    }
    return returnArg;
}


str_commandParts decodeCommand(String commandstring) {
    // Decode the command into parts:
    // Hxx cmd  arg1 arg2 arg3
    str_commandParts returnMsg;
    bool isValidCommand = false;
    int spaceIndex;

    returnMsg.isValidCommand = true;

    commandstring.trim(); // Remove any leading/trailing whitespace
    commandstring.toUpperCase();

    //Hxx
//    if (commandstring.charAt(0) == '?') {
//        returnMsg.isValidCommand = true;
//        returnMsg.cmd = "HLP";
//        return returnMsg;
//    }
    if (commandstring[0] != 'H') {
        returnMsg.isValidCommand = false;
        Println("Invalid command");
        return returnMsg;  //stop
    }

    returnMsg.huis = commandstring.substring(1, 3).toInt();
    if (returnMsg.huis < huisMin || returnMsg.huis > huisMax) {
        returnMsg.isValidCommand = false;
        returnMsg.huis = 0;
        Println("Invalid huis = " + commandstring.substring(1, 3));
        return returnMsg;
    }

    restOfCommand = commandstring.substring(3);
    //cmd
    returnMsg.cmd = decodeRestOfCommand();
    //arg1
    returnMsg.arg1 = decodeRestOfCommand();
    //arg2
    returnMsg.arg2 = decodeRestOfCommand();
    //arg3
    returnMsg.arg3 = decodeRestOfCommand();

    return returnMsg;
}