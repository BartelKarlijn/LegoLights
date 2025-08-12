void cK06kringSat(){
    // Set SAT for Kring
    size_t rgbnr = commandParts.arg1.toInt();
    size_t nr = commandParts.arg2.toInt();
    size_t sat = commandParts.arg3.toInt();
    if (rgbnr >= 0 && rgbnr < RGB_NR_ITEMS) {
        switch (nr) {
            case 1:
                rgbactive[rgbnr].sat1 = sat;
                break;
            case 2:
                rgbactive[rgbnr].sat2 = sat;
                break;
            case 3:
                rgbactive[rgbnr].sat3 = sat;
                break;
            case 4:
                rgbactive[rgbnr].sat4 = sat;
                break;
            default:
                Println("Error: Invalid sat number: " + String(nr));
        }       
    } else {
        Println("Error: Invalid Kring number: " + String(rgbnr));
    }
}
