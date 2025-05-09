void cK06kringSat(){
    // Set SAT for Kring
    int kringnr = commandParts.arg1.toInt();
    int nr = commandParts.arg2.toInt();
    int sat = commandParts.arg3.toInt();
    if (kringnr >= 0 && kringnr < STRIP_NR_ITEMS) {
        switch (nr) {
            case 1:
                kring[kringnr].sat1 = sat;
                break;
            case 2:
                kring[kringnr].sat2 = sat;
                break;
            case 3:
                kring[kringnr].sat3 = sat;
                break;
            case 4:
                kring[kringnr].sat4 = sat;
                break;
            default:
                Println("Error: Invalid sat number: " + String(nr));
        }       
    } else {
        Println("Error: Invalid Kring number: " + String(kringnr));
    }
}
