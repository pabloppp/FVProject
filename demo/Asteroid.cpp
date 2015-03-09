#include "Asteroid.hpp"

void Asteroid::setup() {
    
    gme::RigidBody *rg = new gme::RigidBody;
    rg->setGravity(false);
    rg->isStatic();
    rg->setElasticity(1);
    
    gme::BoxCollider *bc = new gme::BoxCollider;
    //bc->inheritRotation(true);
    bc->setSize(640, 10);
    
    addComponent(rg);
    addComponent(bc);
    
}


