#pragma once
String listKringen(bool ishtml) {
// list van de kringen, if ishtml=true, return html rather than simple text
  String returnText = "";
  Println("Listing kringen van ledstrip");

  for (size_t i = 0; i < STRIP_NR_ITEMS; i++) {
    // telkens ID en beschrijving
    if (ishtml) {
      returnText += "<a href= '/page_maintain_strip?kring=" + String(i) + "' class='button button-center'>" + String(kring[i].desc) + "</a>";
    }
    else {
      returnText += "ID: "+  String(i) + " Beschrijving: " + String(kring[i].desc);
    }
  }
  return returnText;
}
