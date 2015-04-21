
#include "pistolaBullet.hpp"
#include "pbBehavior.hpp"
#include "llbBehavior.hpp"

void pistolaBullet::setup(){
   addTag("bullet"); 
   
   getRenderer()->setTexture("bullet");
   getRenderer()->setSize(gme::Vector2(16,16));
   
   gme::RigidBody *rb = new gme::RigidBody();
   rb->isKinematic();
   addComponent(rb);
   
   pbBehavior *bB = new pbBehavior;
   addComponent(bB);
   
}




