#include "escopetaBullet.hpp"
#include "sbBehavior.hpp"

void escopetaBullet::setup() {
    addTag("bullet"); 
   
   getRenderer()->setTexture("bullet");
   getRenderer()->setSize(gme::Vector2(16,16));
   
   gme::RigidBody *rb = new gme::RigidBody();
   rb->isDynamic();
   rb->setGravity(false);
   rb->setFriction(0);
   addComponent(rb);
   
   gme::BoxCollider *col = new gme::BoxCollider();
   col->setSize(16,16);
   col->isTrigger(true);
   col->addFilterTag("player");
   addComponent(col);
   
   sbBehavior *bB = new sbBehavior;
   addComponent(bB);
}

