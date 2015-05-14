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
    
    getRenderer()->setColor(150,150,255);
    
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
    bc->setSize(gme::Vector2(14*3,14*3));
    addComponent(bc);
  
    LifeManager *stats = new LifeManager();
    stats->maxHp = 15;
    stats->waitTime = 0.3;
    addComponent(stats);
    
    IAfly *ia = new IAfly();
    addComponent(ia);
    
    
}

void enemy_fly::update() {

}

