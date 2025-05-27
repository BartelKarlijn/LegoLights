#pragma once
void str_uit(int kringnr) {
  for (size_t i = kring[kringnr].startrgb; i <= kring[kringnr].stoprgb; i++)
  {
    rgbstrip[i] = CRGB::Black;
  }
  
}