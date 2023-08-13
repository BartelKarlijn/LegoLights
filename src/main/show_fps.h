#pragma once
void show_fps() {
  if(currentMillis > fpsMillis) {
    fpsMillis = currentMillis + SHOWFPSEVERY;
//    fps = cntfps / SHOWFPSEVERY * 1000.00 ;
    Print(cntfps);
    Print(" fps/");
    Print(SHOWFPSEVERY / 1000);
    Println("sec");

    cntfps = 1;  // we willen geen 0 om eventuele delingen door 0 te vermijden
  }
  else {
    cntfps++;
  }
}
