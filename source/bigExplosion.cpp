#include "bigExplosion.hpp"

void bigExplosion::setup() {
    getRenderer()->setTexture("explosion_big");
    getRenderer()->setSize( gme::Vector2(40,64) );
    getRenderer()->setFrame(gme::Vector2(2, 0));
    getRenderer()->setPivot(gme::Vector2(0.5, 0.8));
    
    getTransform()->setScale(gme::Vector2(3,3));
    
    framecount = 0;
}

void bigExplosion::update() {
    if(reloj.currentTime().asSeconds() > 0.01){
        framecount++;
        if(framecount < 22) getRenderer()->setFrame(gme::Vector2(2+framecount, 0));
        else destroyGameObject(gameObject());
        reloj.restart();
    }
}

void bigExplosion::onCollision(gme::Collider* c) {
    if(framecount < 2){       
        if(c->gameObject()->hasTag("player")){
            std::cout << "hitting "+c->gameObject()->getName() << std::endl;
        }
        //
        //else std::cout << "hitting nothing " << std::endl;
        
        if(c->gameObject()->hasTag("enemy")) c->gameObject()->sendMessageUpward("iam", whoami);
        c->gameObject()->sendMessage("damage", 25);
    }
}



bigExplosion::~bigExplosion() {
    
}

