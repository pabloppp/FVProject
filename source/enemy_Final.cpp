#include "enemy_Final.hpp"
#include "IAGirl.hpp"
#include "moveToTop.hpp"

void enemy_Final::setup() {
    
    addTag("enemy");

    getRenderer()->setTexture("chicaJetpack");
    getRenderer()->setSize(gme::Vector2(32, 32));
    getRenderer()->setPivot(gme::Vector2(0.5, 0.8));
    
    getTransform()->setScale(gme::Vector2(3,3));
    
    gme::RigidBody *rb = new gme::RigidBody();
    rb->setGravity(false);
    addComponent(rb);
    
    gme::BoxCollider *bc = new gme::BoxCollider();
    bc->isTrigger(true);
    bc->setSize(16*3, 16*3);
    addComponent(bc);
    
    addComponent(new IAGirl);
    
    moveToTop *mtt = new moveToTop();
    mtt->setOrder(-3);
    addComponent(mtt);
    
    
}

