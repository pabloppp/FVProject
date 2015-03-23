
#include "weapon.hpp"
#include "ShotScript.hpp"

void weapon::setup(){
    
    ad = 50;
    
    std::cout << "weapon setup" << std::endl;
    
    addTag("weapon");
    
    getRenderer()->setTexture("weaponTexture");
    getRenderer()->setSize(gme::Vector2(32,32));
    getRenderer()->setCenter(gme::Vector2(0.5, 0.7));
    ShotScript *shotscript = new ShotScript;
    if(overrideKeys){
        shotscript->ShotKey = ShotKey;
    }
    
    addComponent(shotscript);
}

void weapon::change(){
    
}


