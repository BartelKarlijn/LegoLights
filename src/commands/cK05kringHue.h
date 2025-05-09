void cK05kringHue(){
    // Set HUE for Kring
    int kringnr = commandParts.arg1.toInt();
    int nr = commandParts.arg2.toInt();
    int hue = commandParts.arg3.toInt();
    if (kringnr >= 0 && kringnr < STRIP_NR_ITEMS) {
        switch (nr) {
            case 1:
                kring[kringnr].hue1 = hue;
                break;
            case 2:
                kring[kringnr].hue2 = hue;
                break;
            case 3:
                kring[kringnr].hue3 = hue;
                break;
            case 4:
                kring[kringnr].hue4 = hue;
                break;
            default:
                Println("Error: Invalid hue number: " + String(nr));
        }       
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }
}
