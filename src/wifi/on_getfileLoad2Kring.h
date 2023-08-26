String on_getfileLoad2Kring(AsyncWebServerRequest *request){
    String kringString;
    int kringnr;
    // get parameter kring & veld  http://192.168.68.205/getfileLoad2Kring?kring=1
    if (request->hasParam("kring")) {
      kringString = request->getParam("kring")->value();
      kringnr = kringString.toInt();
    }
    else {
      kringnr = 99;
    }
    return fileLoad2Kring(kringnr);
}