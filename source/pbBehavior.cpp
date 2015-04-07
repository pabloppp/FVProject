
#include "pbBehavior.hpp"

void pbBehavior::setup() {
    winSize = gme::Game::getWindow()->getSize(); 
}

void pbBehavior::update() {
    
    float posX = getTransform()->getPosition().x;
    float posY = getTransform()->getPosition().y;
    
    if((posX < 0 || posX > winSize.x) || (posY < 0 || posY > winSize.y)){
        destroyGameObject(gameObject());
    }
}

pbBehavior::~pbBehavior() {

}



