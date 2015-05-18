#include "enemy_boss.hpp"
#include "LifeManager.hpp"
#include "IAMovement.hpp"
#include "IABoss.hpp"


void enemy_boss::setup(){
    addTag("enemy");
    
    getRenderer()->setTexture("boss00");
    getRenderer()->setSize(gme::Vector2(50,50));
    getRenderer()->setFrame("boss_0");
    getTransform()->scale = gme::Vector2(3,3);
    getRenderer()->setPivot(gme::Vector2(0.5, 1));
    
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
    bc->setSize(gme::Vector2(10*3,18*3));
    addComponent(bc);
  
    LifeManager *stats = new LifeManager();
    stats->maxHp = 60;
    stats->waitTime = 0.8;
    addComponent(stats);
    
    IABoss *ia = new IABoss();
    addComponent(ia);
    
}

void enemy_boss::update(){
    
}



