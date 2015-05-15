
#include "pbBehavior.hpp"
#include "emptyGameObject.hpp"
#include "smallExplosion.hpp"

void pbBehavior::setup() {
    winSize = gme::Game::getWindow()->getSize();
    destroy = false;
    std::vector<gme::GameObject*> gm = gme::GameObject::find("manager");
    if(gm.size() > 0){
        GlobalStateManager *gsm = (GlobalStateManager*)(gm.at(0)->getComponent<GlobalStateManager*>());
        if(gsm != NULL){
            manager = gsm;
        }
    }
}

void pbBehavior::update() {
    if(manager->isPaused()){
        getRigidBody()->setSpeed(0, 0);
        return;
    }
    
    if(myClock.currentTime().asSeconds() > 0.4 || destroy){
        
        //CREAR EXPLOSION
        emptyGameObject *explosion = new emptyGameObject("smallboom");
        explosion->addComponent(new smallExplosion());
        explosion->getTransform()->setPosition(getTransform()->getPosition());
        instantiate(explosion);
        
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
    if(c->gameObject() != NULL){        
        if(c->gameObject()->hasTag("enemy")) c->gameObject()->sendMessageUpward("iam", whoami);
        
        if(c->gameObject()->hasTag("enemy") || c->gameObject()->hasTag("floor") || 
                c->gameObject()->hasTag("colectable")){
            c->gameObject()->sendMessageUpward("damage", 4);
            
            destroy = true;
        }   
        
    }
}




