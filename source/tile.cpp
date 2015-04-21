#include "tile.hpp"

void tile::setup() {
    
    
    addComponent(new gme::RigidBody);
    getRigidBody()->isKinematic();
    getRigidBody()->setFixedRot(true);
    getRigidBody()->setFriction(0);
    getRigidBody()->setElasticity(0);
    getRigidBody()->setWeight(0);
    
    getTransform()->setScale(gme::Vector2(3,3));
  
}

void tile::addCollider() {
    gme::BoxCollider *collider = new gme::BoxCollider;
    collider->setSize(16*3, 16*3);
    collider->isTrigger(true);
    addComponent(collider);
    collider->setup();
    
}



