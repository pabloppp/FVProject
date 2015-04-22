
#include "bullet.hpp"
#include "BulletScript.hpp"

void bullet::setup(){
   addTag("bullet"); 
   
   getRenderer()->setTexture("bulletTexture");
   
   gme::RigidBody *rb = new gme::RigidBody();
   rb->setGravity(false);
   //rb->setSpeed(0,0); 
   
   gme::BoxCollider *boxCollider = new gme::BoxCollider();
   boxCollider->isTrigger(true);
   //boxCollider->setSize();
   
   
   BulletScript *bs = new BulletScript();
      
   addComponent(rb);
   addComponent(boxCollider);
   addComponent(new BulletScript());
}



void bullet::update(){
    
    
}

