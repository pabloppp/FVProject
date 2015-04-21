#include "llamasBullet.hpp"
#include "llbBehavior.hpp"

void llamasBullet::setup() {
    addTag("bullet");
    
    getRenderer()->setTexture("flame_bullet");
    //getRenderer()->setSize(gme::Vector2(16,16));
    
    gme::RigidBody *rb = new gme::RigidBody();
    rb->isKinematic();
    addComponent(rb);
    
    llbBehavior *bB = new llbBehavior;
    addComponent(bB);
}


