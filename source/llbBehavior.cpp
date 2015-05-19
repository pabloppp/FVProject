#include "llbBehavior.hpp"
#include "mainGame.hpp"

void llbBehavior::setup() {
    winSize = gme::Game::getWindow()->getSize();
    destroy = false;
    frame = 0;
    std::vector<gme::GameObject*> gm = gme::GameObject::find("manager");
    if(gm.size() > 0){
        GlobalStateManager *gsm = (GlobalStateManager*)(gm.at(0)->getComponent<GlobalStateManager*>());
        if(gsm != NULL){
            manager = gsm;
        }
    }    
}

void llbBehavior::update() {
    if(manager->isPaused()){
        getRigidBody()->setSpeed(0, 0);
        return;
    }
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
        if(c->gameObject()->hasTag("enemy")) c->gameObject()->sendMessageUpward("iam",whoami);
        if(c->gameObject()->hasTag("enemy") || c->gameObject()->hasTag("floor") || 
                c->gameObject()->hasTag("colectable")){
            c->gameObject()->sendMessageUpward("damage", 0.5f*mainGame::weaponMultiplier);
            destroy = true;
        }
    }
}


llbBehavior::~llbBehavior() {
}

