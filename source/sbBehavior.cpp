#include "sbBehavior.hpp"

void sbBehavior::setup() {
    winSize = gme::Game::getWindow()->getSize();
}

void sbBehavior::update() {
    float posX = getTransform()->getPosition().x;
    float posY = getTransform()->getPosition().y;
    
    if((posX < 0 || posX > winSize.x) || (posY < 0 || posY > winSize.y)){
        destroyGameObject(gameObject());
    }
}

sbBehavior::~sbBehavior() {
}

