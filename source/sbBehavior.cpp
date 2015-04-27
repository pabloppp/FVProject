#include "sbBehavior.hpp"

void sbBehavior::setup() {
    winSize = gme::Game::getWindow()->getSize();
    destroy = false;
}

void sbBehavior::update() {
    if(myClock.currentTime().asSeconds() > 0.3 || destroy){
        destroyGameObject(gameObject());
        return;
    }
    
    float posX = getTransform()->getPosition().x;
    float posY = getTransform()->getPosition().y;
    
    if((posX < 0 || posX > 1584) || (posY < -288 || posY > winSize.y)){
        destroyGameObject(gameObject());
    }
}

sbBehavior::~sbBehavior() {
}

void sbBehavior::onCollision(gme::Collider* c) {
    if(c->gameObject() != NULL){
        if(c->gameObject()->hasTag("enemy") || c->gameObject()->hasTag("floor")){
            c->gameObject()->sendMessageUpward("damage", 10);
            destroy = true;
        }
    }
}


