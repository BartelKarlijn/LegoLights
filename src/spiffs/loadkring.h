#pragma once
String  loadkring(int kringnr) {
// Save Kring settings to file
  char filename[18];
  sprintf(filename, "/cfg/kring%02d.ini", kringnr);

  Print("Filename ");
  Println(String(filename));

//  File file = SPIFFS.open(filename , FILE_WRITE);
//   if (!file){
//    Println("Failed to open file for writing");
//    return;
//  }
//  int bytesWritten = file.print(kring[kringnr]);
//  if (bytesWritten > 0){
//    Println("File was written");
//  } else {
//    Println("File write failed");
//  }
//  file.close();
}