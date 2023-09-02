#pragma once
String listKringen(bool ishtml, String file_img) {
// list van de kringen, if ishtml=true, return html rather than simple text
  String returnText = "";
  Print("Listing kringen van ");
  Println(file_img);

  for (size_t i = 0; i < STRIP_NR_ITEMS; i++) {
    if (kring[i].image == file_img ) {
      // telkens ID en beschrijving
      if (ishtml) {
        returnText += "<a href= '/page_maintain_strip?kring=" + String(i) + "' class='button button-center'>" + kring[i].desc + "</a>";
      }
      else {
        returnText += "ID: "+  String(i) + " Beschrijving: " + kring[i].desc;
      }
    }
  }
  return returnText;
}
