#include "lnzcohetesBullet.hpp"
#include "lbBehavior.hpp"

void lnzcohetesBullet::setup() {
    addTag("bullet");
    
    getRenderer()->setTexture("proj_bullet");
    getTransform()->scale=gme::Vector2(3,3);
   
    gme::RigidBody *rb = new gme::RigidBody();
    rb->isKinematic();
    addComponent(rb);
    
    lbBehavior *lb = new lbBehavior;
    addComponent(lb);
}


