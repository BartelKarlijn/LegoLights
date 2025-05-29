String on_showfirmware(){
  String firmware_info = "Commitpoint: " + String(AUTO_COMMITPT) + "\n";  
  firmware_info += "Compilation date: " + String(__DATE__) + " " + String(__TIME__) + "\n";  

  Println(firmware_info);
  return firmware_info;
}