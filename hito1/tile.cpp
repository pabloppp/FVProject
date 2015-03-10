#include "tile.hpp"

void tile::setup() {
    
    if(texture.length() > 0){
        getRenderer()->setTexture(texture);
        getRenderer()->setSize(size);
        getRenderer()->setFrame(frame);
    }
    
    addComponent(new gme::RigidBody);
    getRigidBody()->isKinematic();
    getRigidBody()->setFixedRot(true);
    
    gme::BoxCollider *collider = new gme::BoxCollider;
    collider->setSize(size.x*3, size.y*3);
    addComponent(collider);
    
    getTransform()->setScale(gme::Vector2(3,3));
}


