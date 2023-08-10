void str_aan(int kring) {
  for (size_t i = str_startled[kring]; i <= str_stopled[kring]; i++)
  {
    ledstrip[i] = str_color1[kring];
  }
  
}