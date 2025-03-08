#include <Arduino.h>

String decodeRestOfCommand (){
    // decode one part of the commandstring and returt the rest
    // restOfCommand is a global variable
    String returnArg;
    int spaceIndex;

    // Looking where command starts
    spaceIndex = restOfCommand.indexOf(' ');
    if (spaceIndex != -1) {
        restOfCommand = restOfCommand.substring(spaceIndex + 1);  
    } else {
        returnArg = "";
        return returnArg;
    }

    // Looking where command ends
    spaceIndex = restOfCommand.indexOf(' ');
    if (spaceIndex != -1) {
        returnArg = restOfCommand.substring(0, spaceIndex);
        Println("cmd or arg: " + returnArg);
        restOfCommand = restOfCommand.substring(spaceIndex + 1);
    } else {
        returnArg = restOfCommand;
        restOfCommand = "";
    }
    
    Println("rest na operatie: " + restOfCommand);
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
    Println("Commandstring: " + commandstring);

    //Hxx
//    if (commandstring.charAt(0) == '?') {
//        returnMsg.isValidCommand = true;
//        returnMsg.cmd = "HLP";
//        return returnMsg;
//    }
    Println("Char0:-" + String(commandstring.charAt(0)) + "-" );
    if (commandstring[0] != 'H') {
        returnMsg.isValidCommand = false;
        Println("Invalid command");
        return returnMsg;  //stop
    }
    Println("Command is correct");

    returnMsg.huis = commandstring.substring(1, 3).toInt();
    if (returnMsg.huis < huisMin || returnMsg.huis > huisMax) {
        returnMsg.isValidCommand = false;
        returnMsg.huis = 0;
        Println("Invalid huis = " + String(returnMsg.huis));
        return returnMsg;
    }
    Print("cmd.huis ");
    Println(returnMsg.huis);

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