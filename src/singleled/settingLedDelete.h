#pragma once
void settingLedDelete(int lednr, int animnr) {
    // Delete one animation from the settings
    ledsettings[lednr].anim[animnr].animdesc = "";
    ledsettings[lednr].anim[animnr].bri = 0;
    ledsettings[lednr].anim[animnr].timeon = 0;
    ledsettings[lednr].anim[animnr].timeoff = 0;
    ledsettings[lednr].anim[animnr].timeeffect = 0;
    ledsettings[lednr].anim[animnr].effect = 0;
    
}