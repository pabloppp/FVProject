#include "staticObject.hpp"
#include "splash.hpp"

void staticObject::setup(){
    if(gme::Game::getCurrentScene()->getName()=="splash"){
        splash *accionSplash = new splash();
        addComponent(accionSplash);
    }

}

