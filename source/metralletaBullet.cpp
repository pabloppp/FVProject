
#include "metralletaBullet.hpp"
#include "mbBehavior.hpp"

metralletaBullet::metralletaBullet(std::string n) : gme::GameObject(n) {
}

void metralletaBullet::setup() {
   addTag("bullet"); 
   
   getRenderer()->setTexture("bullet");
   getRenderer()->setSize(gme::Vector2(16,16));
   
   gme::RigidBody *rb = new gme::RigidBody();
   rb->isKinematic();
   addComponent(rb);
   
   mbBehavior *bB = new mbBehavior;
   addComponent(bB);
}


