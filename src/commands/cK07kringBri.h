void cK07kringBri(){
    // Set BRI for Kring
    int kringnr = commandParts.arg1.toInt();
    int nr = commandParts.arg2.toInt();
    int bri = commandParts.arg3.toInt();
    if (kringnr >= 0 && kringnr < STRIP_NR_ITEMS) {
        switch (nr) {
            case 1:
                kring[kringnr].bri1 = bri;
                break;
            case 2:
                kring[kringnr].bri2 = bri;
                break;
            case 3:
                kring[kringnr].bri3 = bri;
                break;
            case 4:
                kring[kringnr].bri4 = bri;
                break;
            default:
                Println("Error: Invalid bri number: " + String(nr));
        }       
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }

}
