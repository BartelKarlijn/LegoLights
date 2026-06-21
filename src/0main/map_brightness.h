uint8_t map_brightness (unsigned long timeX, unsigned long timeFrom, unsigned long timeTo, uint16_t briFrom, uint16_t briTo) {
// We hebben deze functie nodig omdat de gewone map functie slecht overweg kan met longs.
    float timeXf = (float)timeX;
    float timeFromf = (float)timeFrom;
    float timeTof = (float)timeTo;
    float briFromf = (float)briFrom;
    float briTof = (float)briTo;

    float resultf = (timeXf - timeFromf) * (briTof - briFromf) / (timeTof - timeFromf) + briFromf;

    return (uint8_t)resultf;
    
}