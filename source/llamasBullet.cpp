#include "llamasBullet.hpp"
#include "llbBehavior.hpp"

void llamasBullet::setup() {
    addTag("bullet"); 
   
   getRenderer()->setTexture("fthrower_bullet");
   getRenderer()->setSize(gme::Vector2(16,16));
   getTransform()->resize(gme::Vector2(3,3));
   
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
   
   llbBehavior *bB = new llbBehavior;
   addComponent(bB);
}


