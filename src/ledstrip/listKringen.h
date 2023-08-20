#pragma once
String listKringen(bool ishtml) {
// list van de kringen, if ishtml=true, return html rather than simple text
  String returnText = "";
  Println("Listing kringen van ledstrip");

  if (ishtml) {
    returnText += "<table><tr><th align='left'>ID</th><th align='left'>Beschrijving</th></tr>";
  }
  for (size_t i = 0; i < STRIP_NR_ITEMS; i++) {
    // telkens ID en beschrijving
    if (ishtml) {
      returnText += "<tr align='left'><td>" + String(i) + "</td>";
      returnText += "<td> href= '/page_maintain_strip?kring=" + String(i) + "'" + String(kring[i].desc) + "</td>";
    }
    else {
      returnText += "ID: "+  String(i) + " Beschrijving: " + String(kring[i].desc);
    }
  }
  if (ishtml) {
    returnText += "</table>";
  }
  return returnText;
}
