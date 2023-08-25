String on_getSaveStrip(AsyncWebServerRequest *request){
    String kringString;
    int kringnr;
    // get parameter kring & veld  http://192.168.68.205/getLoadStrip?kring=1
    if (request->hasParam("kring")) {
      kringString = request->getParam("kring")->value();
      kringnr = kringString.toInt();
    }
    else {
      kringnr = 99;
    }

    return savekring(kringnr);
}
