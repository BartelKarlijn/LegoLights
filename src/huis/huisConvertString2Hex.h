uint8_t huisConvertString2Hex (const String &hexString) {
    if (hexString.length() != 2) {
        return 0;
    }

    char hexBytes[3] = { hexString[0], hexString[1], '\0' };
    char *endPtr;
    long value = strtol(hexBytes, &endPtr, 16);

    if (*endPtr != '\0' || value < 0 || value > 0xFF) {
        return 0;
    }

    return (uint8_t)value;
}