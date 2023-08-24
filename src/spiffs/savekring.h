#pragma once
void savekring(int kring) {
// Save Kring settings to file
  char filename[13];
  const char *filebegin = "/cfg/kring";
  char filenr[3];
  Print( "Filebegin " );
  Println(String(filebegin));
  Print("Filenr ");
  Println(filenr);

  sprintf(filenr, "%05d", kring);
  strcpy(filename, filebegin);
  strcat(filename, filenr);

  Print("Filename ");
  Println(String(filename));

//  File file = SPIFFS.open(filename , FILE_WRITE);
  
//  file.close();
}
