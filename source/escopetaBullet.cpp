#include "escopetaBullet.hpp"
#include "sbBehavior.hpp"

void escopetaBullet::setup() {
    addTag("bullet");
    
    getRenderer()->setTexture("bullet");
    getRenderer()->setSize(gme::Vector2(16,16));
   
    gme::RigidBody *rb = new gme::RigidBody();
    rb->isKinematic();
    addComponent(rb);
    
    sbBehavior *sb = new sbBehavior;
    addComponent(sb);
}

