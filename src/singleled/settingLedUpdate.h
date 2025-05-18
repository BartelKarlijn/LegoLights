#pragma once
void settingLedUpdate(int lednr, int animnr) {
    // Insert or Update one animation from the settings
    ledsettings[lednr].leddesc               = ledsingle[lednr].desc;
    ledsettings[lednr].ledimage              = ledsingle[lednr].image;
    ledsettings[lednr].anim[animnr].animdesc = ledsingle[lednr].animatie;
    ledsettings[lednr].anim[animnr].bri      = ledsingle[lednr].bri;
    ledsettings[lednr].anim[animnr].timeon   = ledsingle[lednr].timeon;
    ledsettings[lednr].anim[animnr].timeoff  = ledsingle[lednr].timeoff;
    ledsettings[lednr].anim[animnr].timeeffect = ledsingle[lednr].timeeffect;
    ledsettings[lednr].anim[animnr].effect   = ledsingle[lednr].effect;
}