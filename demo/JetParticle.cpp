#include "JetParticle.hpp"
#include "particleDecay.hpp"
#include "scriptDePrueba.hpp"

void JetParticle::setup(){
    addTag("particle");
    getRenderer()->setTexture("particle1");
    getRenderer()->setSize(gme::Vector2(8,8));
    getTransform()->scale = gme::Vector2(3,3);
    addComponent(new particleDecay());
    
    addComponent(new gme::RigidBody());
    getRigidBody()->setFriction(2);
    gme::BoxCollider *boxCollider = new gme::BoxCollider();
    boxCollider->setSize(20,20);
    //boxCollider->setRadius(10);
    boxCollider->addFilterTag("particle");
    //boxCollider->inheritRotation(true);
    boxCollider->isTrigger(true);
    addComponent(boxCollider);
    
    addComponent(new scriptDePrueba());
}

