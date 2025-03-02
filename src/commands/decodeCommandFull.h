void decodeCommandFull(String command) {
    // check structure of command: 
    commandParts = decodeCommandPart(command); // Decode the command
    Print("Command: "); Println(command);
    Print("CommandParts.comm: "); Println(commandParts.command); 
    Print("CommandParts.nr  : "); Println(commandParts.commandnr); 
    Print("CommandParts.arg : "); Println(commandParts.argument); 
    Print("CommandParts.rest: "); Println(commandParts.restOfCommand); 

    //        executeCommand(command); // Execute the command
// show all commands
// wificonfig: save & show pw
// wifi : show available networks
// wifi: connect to available network
// wifi: setup AP
// wifi: start / stop wifi
// show fps, stop showing fps
// reboot
// geef bord een naam: en nummmer: H01= Olivander, ...
// Kxx: set jpg 
// Kxx: set naam
// Kxx: set startled
// Kxx: set stopled
// Kxx: set every
// Kxx: set Hue1, 2, 3, 4
// Kxx: set Sat1, 2, 3, 4
// Kxx: set Bri1, 2, 3, 4
// Kxx: set timeOn
// Kxx: set timeOff
// Kxx: set timeEffect
// Kxx: set seed
// Kxx: set Effect
// Kxx: save settings
// Kxx: load from last save
// Kxx: reload defaults
}
