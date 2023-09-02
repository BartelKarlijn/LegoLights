String on_getlistKringen(AsyncWebServerRequest *request){
    String answertoSend;
    // get parameter kring & veld  http://192.168.68.205/maintain_strip?kring=1?veld=hue1
    if (request->hasParam("image")) {
      answertoSend = request->getParam("image")->value();
      Println("Image parameter= " + answertoSend);
    }
    else {
      Println("Error, expecting parameter image");
      answertoSend = "";
    }
    return answertoSend;
}
