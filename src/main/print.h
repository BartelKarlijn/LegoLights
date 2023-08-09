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
void Print(uint16_t i){Print(String(i));}

void Println(String TXT){
#ifdef PRINTWEBSERIAL
  WebSerial.println(TXT);
#endif
#ifdef PRINTSERIAL
  Serial.println(TXT);
#endif
}
void Println(uint16_t i){Println(String(i));}
