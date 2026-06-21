#pragma once
void rgb_uit(uint8_t rgbnr) {
  for (uint8_t i = rgbactive[rgbnr].startrgb; i <= rgbactive[rgbnr].stoprgb; i++)
  {
    rgbstrip[i] = CRGB::Black;
  }
  
}