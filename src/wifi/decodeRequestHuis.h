#pragma once
void decodeRequestHuis(AsyncWebServerRequest *request){
    //decode the request into led, anim, veld, waarde
    String answertoSend;
    String ledString;
    String veldString;
    String waardeString;
    if (request->hasParam("led")) {
        ledString = request->getParam("led")->value();
        huisRequest.lednr = ledString.toInt();
      }
      else {
        huisRequest.lednr = 255;
      }
  
    if (request->hasParam("veld")) {
        veldString = request->getParam("veld")->value();
        huisRequest.veld = veldString.toInt();
      }
      else {
        huisRequest.veld = 255;
      }
    if (request->hasParam("waarde")) {
        waardeString = request->getParam("waarde")->value();
        huisRequest.waarde = waardeString;
      }
      else {
        huisRequest.waarde = "";
      }
}
