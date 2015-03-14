#include "tile.hpp"

void tile::setup() {
    
    addTag("destructible");
    
    if(texture.length() > 0){
        getRenderer()->setTexture(texture);
        getRenderer()->setSize(size);
        getRenderer()->setFrame(frame);
    }
    
    
    addComponent(new gme::RigidBody);
    getRigidBody()->isKinematic();
    getRigidBody()->setFixedRot(true);
    getRigidBody()->setFriction(0);
    getRigidBody()->setElasticity(0);
    getRigidBody()->setWeight(0);
    
    
    gme::BoxCollider *collider = new gme::BoxCollider;
    collider->setSize(size.x*3, size.y*3);
    collider->isTrigger(true);
    addComponent(collider);
    
    
    getTransform()->setScale(gme::Vector2(3,3));
}


