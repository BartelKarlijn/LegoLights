#pragma once
void rgb_uit(size_t rgbnr) {
  for (size_t i = rgbactive[rgbnr].startrgb; i <= rgbactive[rgbnr].stoprgb; i++)
  {
    rgbstrip[i] = CRGB::Black;
  }
  
}