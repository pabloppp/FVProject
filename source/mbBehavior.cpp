
#include "mbBehavior.hpp"

void mbBehavior::setup() {
    winSize = gme::Game::getWindow()->getSize(); 
}

void mbBehavior::update() {
    float posX = getTransform()->getPosition().x;
    float posY = getTransform()->getPosition().y;
    
    if((posX < 0 || posX > winSize.x) || (posY < 0 || posY > winSize.y)){
        destroyGameObject(gameObject());
    }
}

mbBehavior::~mbBehavior() {
}

