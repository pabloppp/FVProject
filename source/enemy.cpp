
#include "enemy.hpp"
#include "LifeManager.hpp"
#include "IAMovement.hpp"


void enemy::setup(){
    addTag("enemy");
    
    getRenderer()->setTexture("dino00");
    getRenderer()->setSize(gme::Vector2(32,32));
    getRenderer()->setFrame("idle");
    getTransform()->scale = gme::Vector2(3,3);
    getRenderer()->setPivot(gme::Vector2(0.5, 1));
    
    gme::RigidBody *rb = new gme::RigidBody();
    rb->setElasticity(0);
    
    rb->setWeight(5);
    rb->isDynamic(); //??
    rb->gravityMultiplier(5);  
    rb->setFixedRot(true);
    
    addComponent(rb);
    
    gme::BoxCollider *bc = new gme::BoxCollider();
    bc->addFilterTag("player");
    bc->addFilterTag("enemy");
    bc->setSize(gme::Vector2(10*3,18*3));
    addComponent(bc);
  
    LifeManager *stats = new LifeManager();
    stats->maxHp = 10;
    stats->waitTime = 0.05;
    addComponent(stats);
    
    IAMovement *ia =  new IAMovement();
    addComponent(ia);
   
}




