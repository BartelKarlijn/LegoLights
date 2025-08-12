// Configuration file for commands
//////// command //////////
struct struc_commandParts {
    bool isValidCommand;
    size_t  huis;
    String  cmd;
    String arg1;
    String arg2;
    String arg3;
};
struc_commandParts commandParts;

//huis
size_t huisMin = 1;
size_t huisMax = 20;

struct struc_huisRequest {
    size_t huisnr;
    size_t animnr;
    size_t veld;
    size_t lednr;
    size_t rgbnr;
    String waarde;
};
struc_huisRequest huisRequest;

// led
struct struc_ledRequest {
    size_t lednr;
    size_t veld;
    String waarde;
};
struc_ledRequest ledRequest;

// rgb
struct struc_rgbRequest {
    size_t rgbnr;
    size_t veld;
    String waarde;
};
struc_rgbRequest rgbRequest;
