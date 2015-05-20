#include "jaula.hpp"
#include "jaulaScript.hpp"
#include "moveToTop.hpp"

void jaula::setup() {
    getRenderer()->setTexture("jaula");
    getRenderer()->setSize(gme::Vector2(128,128));
    getRenderer()->setPivot(gme::Vector2(0.5, 0));
    
    getTransform()->setPosition(gme::Vector2(600, -300));
    getTransform()->setScale(gme::Vector2(3,3));
    
    gme::RigidBody *rb = new gme::RigidBody();
    rb->gravityMultiplier(0);
    addComponent(rb);
    
    gme::BoxCollider *bc = new gme::BoxCollider();
    bc->isTrigger(true);
    bc->setSize(8*3, 128*3);
    addComponent(bc);
    
    
    addComponent(new jaulaScript());
    
    moveToTop *mtt = new moveToTop();
    mtt->setOrder(-5);
    addComponent(mtt);
    
}


