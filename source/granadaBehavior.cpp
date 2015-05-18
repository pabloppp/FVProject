#include "granadaBehavior.hpp"
#include "bigExplosion.hpp"
#include "emptyGameObject.hpp"
#include "mainGame.hpp"

void granadaBehavior::setup() {
    timeToExplode = 1.4;
    
    granada_sound = new gme::SoundPlayer();
    granada_sound->setSound("granada");
    
}

void granadaBehavior::update() {
    
    int redment = (int)(250.0f * timerClock.currentTime().asSeconds() / timeToExplode); 
    
    float inflation = 3.0f * 4*(timerClock.currentTime().asSeconds() - 3*timeToExplode/4.f) / timeToExplode; 
    if(inflation < 0) inflation = 0;
    
    getRenderer()->setColor(255, 255-redment, 255-redment);
    getTransform()->setScale(gme::Vector2(3+inflation, 3+inflation));
    
    if(timerClock.currentTime().asSeconds() > timeToExplode || forceExplode){
        
        emptyGameObject *explosion = new emptyGameObject("bigboom");
        bigExplosion *be = new bigExplosion();
        if(mainGame::sound)granada_sound->play();
        be->whoami = whoami;
        explosion->addComponent(be);
        explosion->getTransform()->setPosition(getTransform()->getPosition());
        
        gme::RigidBody *rb = new gme::RigidBody();
        rb->isDynamic();
        rb->setElasticity(0);
        rb->setFriction(0);
        rb->setWeight(0);
        rb->gravityMultiplier(0);

        explosion->addComponent(rb);

        gme::BoxCollider *col = new gme::BoxCollider();
        col->isTrigger(true);
        col->setSize(40*3, 40*3);

        explosion->addComponent(col);
        
        instantiate(explosion);
        
        destroyGameObject(gameObject());
    }
}

void granadaBehavior::onCollision(gme::Collider* c) {
    if(c->gameObject()->hasTag("enemy") || c->gameObject()->hasTag("bullet")){
        forceExplode = true;
    }
}



granadaBehavior::~granadaBehavior() {
}

