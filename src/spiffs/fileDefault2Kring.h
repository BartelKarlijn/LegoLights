#pragma once
String  fileDefault2Kring(int kringnr) {
// Load Kring settings from defaults stored hardcoded
  kring[kringnr] = STR_DEFAULT[kringnr];

  return ("Default teruggezet voor " + kring[kringnr].desc);
}
