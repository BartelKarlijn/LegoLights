#pragma once
void show_fps() {
  double fps;
  if(currentMillis > fpsMillis) {
    fpsMillis = currentMillis + SHOWFPSEVERY;
    fps = double(cntfps) / double(SHOWFPSEVERY) * 1000.00 ;
    Print(String(fps));
    Println(" fps");

    cntfps = 1;  // we willen geen 0 om eventuele delingen door 0 te vermijden

  }
  else {
    cntfps++;
  }
}
