#include "llbBehavior.hpp"

void llbBehavior::setup() {
    
}

void llbBehavior::update() {
    if(clock.currentTime().asSeconds()>0.3){
        destroyGameObject(gameObject());
    }
}

llbBehavior::~llbBehavior() {
}

