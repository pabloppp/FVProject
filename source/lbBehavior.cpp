#include "lbBehavior.hpp"

void lbBehavior::setup() {
     winSize = gme::Game::getWindow()->getSize();
}

void lbBehavior::update() {
    float posX = getTransform()->getPosition().x;
    float posY = getTransform()->getPosition().y;
    
    if((posX < 0 || posX > winSize.x) || (posY < 0 || posY > winSize.y)){
        destroyGameObject(gameObject());
    }
}


lbBehavior::~lbBehavior() {
}

