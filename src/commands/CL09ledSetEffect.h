void cL09ledSetEffect(){
    // Set On Off time to Led
    size_t lednr = commandParts.arg1.toInt();
    size_t Effect = commandParts.arg2.toInt();  //aparently toInt also converts to long
    size_t tEffect = commandParts.arg3.toInt();

    Println("L09 Set Effect " + commandParts.arg1 + " Effect= " + commandParts.arg2 + ", timeEffect= " + commandParts.arg3);
    if (lednr >= 0 && lednr < LED_NR_ITEMS) {
        switch (Effect){
        case EFFLED_AAN:
            ledactive[lednr].effect = EFFLED_AAN;
            break;
        case EFFLED_FIRE:
            ledactive[lednr].effect = EFFLED_FIRE;
            break;
        case EFFLED_GLOW:
            ledactive[lednr].effect = EFFLED_GLOW;
            break;
        case EFFLED_RAMP:
            ledactive[lednr].effect = EFFLED_RAMP;
            break;
        case EFFLED_RAND:
            ledactive[lednr].effect = EFFLED_RAND;
            break;
        case EFFLED_UIT:
            ledactive[lednr].effect = EFFLED_UIT;
            break;
        case EFFLED_DELAY:
            ledactive[lednr].effect = EFFLED_DELAY;
            break;
        default:
            Println("Invalid effect value");
            break;
        }
        if (tEffect >= 0) {
            ledactive[lednr].timeeffect = tEffect;
        } else {
            Println("Invalid time value(s)");
        }    

    }
    return;
}
