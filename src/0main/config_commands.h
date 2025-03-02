// Configuration file for commands
//////// command //////////
struct str_commandParts {
    bool isValidCommand;
    char command;
    int  commandnr;
    String argument;
    String restOfCommand;
};
str_commandParts commandParts;

const std::vector<char>& validChars = 
{     'H'   //Huisje
    , 'W'   //wifi
};

