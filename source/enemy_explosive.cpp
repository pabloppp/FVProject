

#include "enemy_explosive.hpp"
#include "LifeManager.hpp"
#include "IAexplosive.hpp"



void enemy_explosive::setup() {
    addTag("enemy");
    
    getRenderer()->setTexture("explosive");
    getTransform()->scale = gme::Vector2(3,3);
    getRenderer()->setPivot(gme::Vector2(0.5, 0.5));
    
    getRenderer()->setColor(150,150,255);
    
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
    bc->setSize(gme::Vector2(14*3,14*3));
    addComponent(bc);
  
    LifeManager *stats = new LifeManager();
    stats->maxHp = 15;
    stats->waitTime = 0.05;
    addComponent(stats);
    
    IAexplosive *ia =  new IAexplosive();
    addComponent(ia);
    
   
}

void enemy_explosive::update() {

}

