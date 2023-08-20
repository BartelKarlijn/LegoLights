String html_processorRoot(const String& var){
// Replaces placeholder with button section in your web page
  if(var == "BUTTONPLACEHOLDER"){
    String buttons = "";
    buttons += "<h1>" + String(NAME_ACCESSPOINT) + "</h1><table>";

    buttons += html_buttonSimple(id_SaveConfig, "SAVE", oms_SaveConfig);
    buttons += html_buttonSimple(id_Restart, "/!\\", oms_Restart);
    buttons += "</table>";

    buttons += html_buttonLink("Wifi Management", "/wificfg");
    buttons += html_buttonLink("WebSerial", "/webserial");
    buttons += html_buttonLink("Firmware update", "/update");
    
    buttons += "<p>Build commit= " + String(AUTO_COMMITPT);
    buttons += ", Compilation date= " + String(__DATE__) ;
    buttons += ",  time= " + String(__TIME__) + "</p>";

    return buttons;
  }
  return String();
}

String html_processorWifi(const String& var){
// Replaces placeholder with wifi section
  if(var == "BUTTONPLACEHOLDER"){
    String buttons = "";
    buttons += "<h1>Wifi instellen</h1>";
//    buttons += "<form action=\"/scan\" method=\"POST\"><input type=\"submit\" value=\"scan\"></form>";
    buttons += wifi_scan;
    buttons += html_doubleInput(oms_WifiSave, PARAM_ssid, PARAM_pwd, 32, "/wifisave");
//    buttons += "</p><form method='get' action='wifisave'><label>SSID: </label><input name='ssid' length=32><input name='pwd' length=64><input type='submit'></form><br>";
    buttons += html_buttonSimple(id_Restart, "/!\\", oms_Restart);
    buttons += html_buttonLink("naar Root", "/");
    return buttons;
  }
  return String();
}
