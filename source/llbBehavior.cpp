#include "llbBehavior.hpp"

void llbBehavior::setup() {
    winSize = gme::Game::getWindow()->getSize();
    destroy = false;
    frame = 0;
    
}

void llbBehavior::update() {
    if(clock.currentTime().asSeconds() > 0.8 || destroy){
        destroyGameObject(gameObject());
        return;
    }
    
    if(frame == 3){
        getRigidBody()->setSpeed(getRigidBody()->getSpeed().x, -5);
        initialXSpeed = getRigidBody()->getSpeed().x;
    }
    if(frame > 3) getRigidBody()->setSpeed(initialXSpeed/3.0, -5);
    
    if(animclock.currentTime().asSeconds() > 0.5/5.0){
        animclock.restart();
        frame++;
        if(frame < 5) getRenderer()->setFrame(gme::Vector2(frame,0));
    }
    
    float posX = getTransform()->getPosition().x;
    float posY = getTransform()->getPosition().y;
    
    if((posX < 0 || posX > 1584) || (posY < -288 || posY > winSize.y)){
        destroyGameObject(gameObject());
    }
}

void llbBehavior::onCollision(gme::Collider* c) {
    if(frame <= 3 && c->gameObject() != NULL){
        if(c->gameObject()->hasTag("enemy") || c->gameObject()->hasTag("floor") || 
                c->gameObject()->hasTag("colectable")){
            c->gameObject()->sendMessageUpward("damage", 0.1);
            destroy = true;
        }
    }
}


llbBehavior::~llbBehavior() {
}

