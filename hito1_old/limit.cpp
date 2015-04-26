#include "limit.hpp"

void limit::setup() {
    
    //addTag("limit");
    getTransform()->position = position;
    
    gme::RigidBody *rigidbody = new gme::RigidBody;
    rigidbody->isStatic();
    addComponent(rigidbody);
    
    gme::BoxCollider *boxcollider = new gme::BoxCollider;
    boxcollider->setSize(width, height);
    
    boxcollider->addFilterTag("enemy");
    boxcollider->addFilterTag("particle");
    boxcollider->addFilterTag("bullet");
    addComponent(boxcollider);
    
   
    
}


