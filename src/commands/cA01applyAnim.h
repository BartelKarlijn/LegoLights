void cA01applyAnim(){
  // Apply animation
  uint8_t anim = commandParts.arg1.toInt();
  if (anim < 0 || anim > HUIS_NR_ANIM) {
    Println(F("Invalid animation number"));
  }
  else {
    huisRequest.animnr = anim;
    huisAnimApply();
  }
}