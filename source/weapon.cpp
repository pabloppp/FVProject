#include "weapon.hpp"


void weapon::setup(){
    
    getRenderer()->setSize(gme::Vector2(32,32));
    getTransform()->setPosition(gme::Vector2(500,350));
    getTransform()->scale = gme::Vector2(3,3);
    /*ShotScript *shotscript = new ShotScript;
    if(overrideKeys){
        shotscript->ShotKey = ShotKey;
    }
    addComponent(shotscript);*/   
}



