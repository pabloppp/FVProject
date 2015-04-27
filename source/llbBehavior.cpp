#include "llbBehavior.hpp"

void llbBehavior::setup() {
    winSize = gme::Game::getWindow()->getSize();
    destroy = false;
}

void llbBehavior::update() {
    if(clock.currentTime().asSeconds() > 0.3 || destroy){
        destroyGameObject(gameObject());
        return;
    }
    
    float posX = getTransform()->getPosition().x;
    float posY = getTransform()->getPosition().y;
    
    if((posX < 0 || posX > 1584) || (posY < -288 || posY > winSize.y)){
        destroyGameObject(gameObject());
    }
}

void llbBehavior::onCollision(gme::Collider* c) {
    if(c->gameObject() != NULL){
        if(c->gameObject()->hasTag("enemy") || c->gameObject()->hasTag("floor")){
            c->gameObject()->sendMessageUpward("damage", 1);
            destroy = true;
        }
    }
}


llbBehavior::~llbBehavior() {
}

