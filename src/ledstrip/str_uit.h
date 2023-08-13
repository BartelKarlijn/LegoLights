#pragma once
void str_uit(int kringnr) {
  for (size_t i = kring[kringnr].startled; i <= kring[kringnr].stopled; i++)
  {
    ledstrip[i] = CRGB::Black;
  }
  
}