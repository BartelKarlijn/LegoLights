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
void Print(uint32_t i)     {Print(String(i));}
void Print(uint16_t i)     {Print(String(i));}
void Print(size_t i)       {Print(String(i));}
void Print(int i)          {Print(String(i));}
void Print(int32_t i)      {Print(String(i));}
void Print(float i)        {Print(String(i));}

void Println(String TXT){
  #ifdef PRINTWEBSERIAL
    WebSerial.println(TXT);
  #endif
  #ifdef PRINTSERIAL
    Serial.println(TXT);
  #endif
}
void Println(uint32_t i)     {Println(String(i));}
void Println(uint16_t i)     {Println(String(i));}
void Println(size_t i)       {Println(String(i));}
void Println(int i)          {Println(String(i));}
void Println(int32_t i)      {Println(String(i));}
void Println(float i)        {Println(String(i));}
