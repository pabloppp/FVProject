
#include "enemy.hpp"

void enemy::setup(){
    life = 150;
    
    addTag("enemy");
    
    getRenderer()->setTexture("enemyTexture");
    getRenderer()->setSize(gme::Vector2(32,32));
    getTransform()->scale = gme::Vector2(3,3);
    
    gme::RigidBody *rb = new gme::RigidBody();
    rb->setGravity(true);
    rb->setWeight(20);
    rb->gravityMultiplier(5);
    rb->isDynamic(); //??
    
    addComponent(rb);
    
    gme::BoxCollider *bc = new gme::BoxCollider();
    //bc->setSize(gme::Vector2(10*3,7*3));
    
    addComponent(bc);
}

void enemy::update(){
    
}

