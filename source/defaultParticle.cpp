/* 
 * File:   defaultParticle.cpp
 * Author: pablopernias
 * 
 * Created on 23 de abril de 2015, 22:47
 */

#include "defaultParticle.hpp"
#include "sprayParticleScript.hpp"

void defaultParticle::setup() {
    
    addTag("particle");
    
    getRenderer()->setTexture("spray_particle");
    getRenderer()->setSize(gme::Vector2(8,8));
    getRenderer()->setPivot(gme::Vector2(0.5, 1));
    
    getRenderer()->setFrame(gme::Vector2((rand() % 3), 0));
    getTransform()->scale = gme::Vector2(3,3);
    
    
    gme::RigidBody *rb = new gme::RigidBody();
    rb->setElasticity(0);
    rb->gravityMultiplier(5);
    rb->setFriction(0.5);
    rb->isDynamic();
    addComponent(rb);
    
    gme::BoxCollider *bc = new gme::BoxCollider();
    bc->setSize(gme::Vector2(6,6));
    bc->addFilterTag("enemy");
    bc->addFilterTag("player");
    bc->addFilterTag("particle");
    bc->addFilterTag("bullet");
    addComponent(bc);
    
    addComponent(new sprayParticleScript());
    
    getTransform()->setPosition(startingPosition);
}


