// Configuration file for commands
//////// command //////////
struct struc_commandParts {
    bool isValidCommand;
    int  huis;
    String  cmd;
    String arg1;
    String arg2;
    String arg3;
};
struc_commandParts commandParts;

//huis
int huisMin = 1;
int huisMax = 20;

struct struc_huisRequest {
    int huisnr;
    int veld;
    int lednr;
    int rgbnr;
    String waarde;
};
struc_huisRequest huisRequest;

// led
struct struc_ledRequest {
    int lednr;
    int animnr;
    int veld;
    String waarde;
};
struc_ledRequest ledRequest;

// rgb
struct struc_rgbRequest {
    int rgbnr;
    int animnr;
    int veld;
    String waarde;
};
struc_rgbRequest rgbRequest;
