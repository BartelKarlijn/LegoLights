#pragma once
void decodeRequestLed(AsyncWebServerRequest *request){
    //decode the request into led, anim, veld, waarde
    String answertoSend;
    String ledString;
    String animString;
    String veldString;
    String waardeString;
    if (request->hasParam("led")) {
        ledString = request->getParam("led")->value();
        ledRequest.lednr = ledString.toInt();
      }
      else {
        ledRequest.lednr = 255;
      }
  
    if (request->hasParam("anim")) {
        animString = request->getParam("anim")->value();
        ledRequest.animnr = animString.toInt();
      }
      else {
        ledRequest.animnr = 255;
      }
    if (request->hasParam("veld")) {
        veldString = request->getParam("veld")->value();
        ledRequest.veld = veldString.toInt();
      }
      else {
        ledRequest.veld = 255;
      }
    if (request->hasParam("waarde")) {
        waardeString = request->getParam("waarde")->value();
        ledRequest.waarde = waardeString;
      }
      else {
        ledRequest.waarde = "";
      }
}
