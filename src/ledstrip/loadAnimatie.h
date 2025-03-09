#pragma once
void loadAnimatie() {
  String msgReceive;
  // Eerst ini file lezen, en terugvallen op default als niet gelukt.
  //huis
  if (fileLoad2Huis() == "File does not exist") {
    Println("Fallback to default for huis"); delay(5);
    msgReceive = fileDefault2Huis();
  };

  // kringen
  for (size_t i = 0; i < STRIP_NR_ITEMS; i++) {
    if (fileLoad2Kring(i) == "File does not exist") {
      Println("Fallback to default for " + String(i)); delay(5);
      msgReceive = fileDefault2Kring(i);
    };
  }
}
