#include "llamasBullet.hpp"
#include "llbBehavior.hpp"

void llamasBullet::setup() {
    addTag("bullet");
    
    getRenderer()->setTexture("flame_bullet");
    
    gme::RigidBody *rb = new gme::RigidBody();
    rb->isKinematic();
    addComponent(rb);
    
    llbBehavior *bB = new llbBehavior;
    addComponent(bB);
}


