#include "genericEnemy.hpp"

void genericEnemy::setup() {
    addTag("enemy");
    
    getRenderer()->setTexture("dino");
    getRenderer()->setFrame("idle");
    getRenderer()->setPivot(gme::Vector2(0.5,1));
    getTransform()->scale = gme::Vector2(-3,3);
    
    gme::RigidBody *rigidbody = new gme::RigidBody;
    rigidbody->setWeight(200);
    rigidbody->isDynamic();
    rigidbody->setFriction(0.01);
    rigidbody->gravityMultiplier(3);
    rigidbody->setFixedRot(true);
    addComponent(rigidbody);
    
    gme::BoxCollider *collider = new gme::BoxCollider;
    collider->setSize(15*3,15*3);
    collider->addFilterTag("enemy");
    addComponent(collider);
    
}


