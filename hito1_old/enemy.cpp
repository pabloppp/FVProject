
#include "enemy.hpp"
#include "LifeManager.hpp"


void enemy::setup(){
    addTag("enemy");
    
    getRenderer()->setTexture("enemyTexture");
    getRenderer()->setSize(gme::Vector2(32,32));
    getTransform()->scale = gme::Vector2(3,3);
    
    gme::RigidBody *rb = new gme::RigidBody();
    
    rb->setWeight(20);
    rb->gravityMultiplier(5);
    rb->isDynamic(); //??
    rb->setGravity(false);
    addComponent(rb);
    
    gme::BoxCollider *bc = new gme::BoxCollider();
    //bc->setSize(gme::Vector2(10*3,7*3));
    
    addComponent(bc);
    
    LifeManager *stats = new LifeManager();    
    addComponent(stats);
    
    
}

void enemy::update(){
    
}



