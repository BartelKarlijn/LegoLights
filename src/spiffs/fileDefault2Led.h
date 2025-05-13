#pragma once
String  fileDefault2Led(int lednr) {
// Load Led settings from defaults stored hardcoded
ledsingle[lednr] = ledsingle[lednr];

  return ("Default teruggezet voor " + ledsingle[lednr].desc);
}
