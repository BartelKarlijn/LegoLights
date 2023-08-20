void on_fileUpload(AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final) {

    if (!index) {
      // open the file on first call and store the file handle in the request object
      request->_tempFile = SPIFFS.open("/" + filename, "w");
      Println("Upload Start: " + String(filename));
    }

    if (len) {
      // stream the incoming chunk to the opened file
      request->_tempFile.write(data, len);
      Println("Writing file: " + String(filename) + " index=" + String(index) + " len=" + String(len));
    }

    if (final) {
      // close the file handle as the upload is now done
      request->_tempFile.close();
      Println("Upload Complete: " + String(filename) + ",size: " + String(index + len));
      request->redirect("/");
    }
}