#pragma once
void loadAnimatie() {
  String msgReceive;
  // Eerst ini file lezen, en terugvallen op default als niet gelukt.
  for (size_t i = 0; i < STRIP_NR_ITEMS; i++) {
    if (fileLoad2Kring(i) = "File does not exist") {
      msgReceive = fileDefault2Kring(i);
    };
  }
}
