void CL09ledSetEffect(){
    // Set On Off time to Led
    int lednr = commandParts.arg1.toInt();
    int Effect = commandParts.arg2.toInt();  //aparently toInt also converts to long
    int tEffect = commandParts.arg3.toInt();

    Println("L09 Set Effect " + commandParts.arg1 + " Effect= " + commandParts.arg2 + ", timeEffect= " + commandParts.arg3);
    if (lednr >= 0 && lednr < LED_NR_ITEMS) {
        switch (Effect){
        case EFFLED_AAN:
            ledsingle[lednr].effect = EFFLED_AAN;
            break;
        case EFFLED_FIRE:
            ledsingle[lednr].effect = EFFLED_FIRE;
            break;
        case EFFLED_GLOW:
            ledsingle[lednr].effect = EFFLED_GLOW;
            break;
        case EFFLED_RAMP:
            ledsingle[lednr].effect = EFFLED_RAMP;
            break;
        case EFFLED_RAND:
            ledsingle[lednr].effect = EFFLED_RAND;
            break;
        case EFFLED_UIT:
            ledsingle[lednr].effect = EFFLED_UIT;
            break;
        default:
            Println("Invalid effect value");
            break;
        }
        if (tEffect >= 0) {
            ledsingle[lednr].timeeffect = tEffect;
        } else {
            Println("Invalid time value(s)");
        }    

    }
    return;
}
