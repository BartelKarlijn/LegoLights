#pragma once
void decodeRequestRgb(AsyncWebServerRequest *request){
    //decode the request into rgb, anim, veld, waarde
    String answertoSend;
    String rgbString;
    String veldString;
    String waardeString;
    if (request->hasParam("rgb")) {
        rgbString = request->getParam("rgb")->value();
        rgbRequest.rgbnr = rgbString.toInt();
      }
      else {
        rgbRequest.rgbnr = 255;
      }
    if (request->hasParam("veld")) {
        veldString = request->getParam("veld")->value();
        rgbRequest.veld = veldString.toInt();
      }
      else {
        rgbRequest.veld = 255;
      }
    if (request->hasParam("waarde")) {
        waardeString = request->getParam("waarde")->value();
        rgbRequest.waarde = waardeString;
      }
      else {
        rgbRequest.waarde = "";
      }
}
