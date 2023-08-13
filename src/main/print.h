#pragma once
void Print(String TXT){
  #ifdef PRINTWEBSERIAL
    if (flagWifiOn) {
      WebSerial.print(TXT);
    }
  #endif
  #ifdef PRINTSERIAL
    Serial.print(TXT);
  #endif
  }
void Print(uint16_t i)     {Print(String(i));}
void Print(unsigned long i){Print(String(i));}
void Print(int i)          {Print(String(i));}
void Print(float i)        {Print(String(i));}

void Println(String TXT){
  #ifdef PRINTWEBSERIAL
    WebSerial.println(TXT);
  #endif
  #ifdef PRINTSERIAL
    Serial.println(TXT);
  #endif
}
void Println(uint16_t i)     {Println(String(i));}
void Println(unsigned long i){Println(String(i));}
void Println(int i)          {Println(String(i));}
void Println(float i)        {Println(String(i));}
