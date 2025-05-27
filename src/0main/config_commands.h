// Configuration file for commands
//////// command //////////
struct str_commandParts {
    bool isValidCommand;
    int  huis;
    String  cmd;
    String arg1;
    String arg2;
    String arg3;
};
str_commandParts commandParts;

// led
struct str_ledRequest {
    int lednr;
    int animnr;
    int veld;
    String waarde;
};

str_ledRequest ledRequest;

//huis
int huisMin = 1;
int huisMax = 20;

struct struc_huisRequest {
    int huisnr;
    int veld;
    int lednr;
    String waarde;
};

struc_huisRequest huisRequest;
