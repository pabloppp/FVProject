/* 
 * File:   enemy_fly.cpp
 * Author: albertomartinezmartinez
 * 
 * Created on 12 de mayo de 2015, 18:39
 */

#include "enemy_fly.hpp"
#include "LifeManager.hpp"
#include "IAfly.hpp"

void enemy_fly::setup() {
    
    addTag("enemy");
    
   getRenderer()->setTexture("fly");
   
    getTransform()->scale = gme::Vector2(3,3);
    getRenderer()->setPivot(gme::Vector2(0.5, 0.5));
    getRenderer()->setSize(gme::Vector2(32,32));
    getRenderer()->setFrame("fly_1");
    //getTransform()->resize(gme::Vector2(-1,1));
    
    getRenderer()->setColor(255,255,255);
    
    gme::RigidBody *rb = new gme::RigidBody();
    rb->setElasticity(0);
    
    rb->setWeight(5);
    rb->isDynamic(); //?? 
    rb->setGravity(false);
    rb->setFixedRot(true);
    
    addComponent(rb);
    
    gme::BoxCollider *bc = new gme::BoxCollider();
    bc->addFilterTag("player");
    bc->addFilterTag("enemy");
    if(enemy_boss) bc->addFilterTag("floor");
    bc->setSize(gme::Vector2(14*3,14*3));
    addComponent(bc);
  
    LifeManager *stats = new LifeManager();
    if(!enemy_boss) stats->maxHp = 15;
    else stats->maxHp = 40;
    stats->waitTime = 0.8;
   
    std::cout << stats->maxHp << std::endl;
    addComponent(stats);
    
    IAfly *ia = new IAfly(enemy_boss);
    addComponent(ia);
    
    
}

void enemy_fly::update() {

}

