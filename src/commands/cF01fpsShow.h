void cF01fpsShow(){
    // Show or stopshowing fps
    int showint = commandParts.arg1.toInt();
    switch (showint) {
        case 0:
            flagShowFps = false;
            break;
        case 1:
            flagShowFps = true;
            break;
        default:
            break;
    }
}
