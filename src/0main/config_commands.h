// Configuration file for commands
//////// command //////////
struct struc_commandParts {
    bool isValidCommand;
    uint8_t  huis;
    String  cmd;
    String arg1;
    String arg2;
    String arg3;
};
struc_commandParts commandParts;

//huis
uint8_t huisMin = 1;
uint8_t huisMax = 20;

struct struc_huisRequest {
    uint8_t huisnr;
    uint8_t animnr;
    uint8_t veld;
    uint8_t lednr;
    uint8_t rgbnr;
    String waarde;
};
struc_huisRequest huisRequest;

// led
struct struc_ledRequest {
    uint8_t lednr;
    uint8_t animnr;
    uint8_t veld;
    String waarde;
};
struc_ledRequest ledRequest;

// rgb
struct struc_rgbRequest {
    uint8_t rgbnr;
    uint8_t animnr;
    uint8_t veld;
    String waarde;
};
struc_rgbRequest rgbRequest;
