
#include "pbBehavior.hpp"

void pbBehavior::setup() {
    winSize = gme::Game::getWindow()->getSize();
    destroy = false;
}

void pbBehavior::update() {
    
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

pbBehavior::~pbBehavior() {

}

void pbBehavior::onCollision(gme::Collider* c) {
    std::cout << c->gameObject()->getName() << std::endl;
    if(c->gameObject()->hasTag("enemy") || c->gameObject()->hasTag("floor")){
        c->gameObject()->sendMessage("damage", 2);
        destroy = true;
    }
}




