
#include "mbBehavior.hpp"

void mbBehavior::setup() {
    winSize = gme::Game::getWindow()->getSize(); 
    destroy = false;
}

void mbBehavior::update() {
    if(myClock.currentTime().asSeconds() > 0.4 || destroy){
        destroyGameObject(gameObject());
        return;
    }
    
    float posX = getTransform()->getPosition().x;
    float posY = getTransform()->getPosition().y;
    
    if((posX < 0 || posX > 1584) || (posY < -288 || posY > winSize.y)){
        destroyGameObject(gameObject());
    }
}

void mbBehavior::onCollision(gme::Collider* c) {
    if(c->gameObject() != NULL){
        if(c->gameObject()->hasTag("enemy") || c->gameObject()->hasTag("floor") || 
                c->gameObject()->hasTag("colectable")){
            c->gameObject()->sendMessageUpward("damage", 1);
            destroy = true;
        }
    }
}


mbBehavior::~mbBehavior() {
}

