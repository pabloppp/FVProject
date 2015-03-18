#include "genericEnemy.hpp"

void genericEnemy::setup() {
    addTag("enemy");
    
    getRenderer()->setTexture("alien");
    getRenderer()->setSize(gme::Vector2(48,48));
    getRenderer()->setFrame(gme::Vector2(18,0));
    getRenderer()->setCenter(gme::Vector2(0.5, 0.81));
    getTransform()->scale = gme::Vector2(3,3);
    
    gme::RigidBody *rigidbody = new gme::RigidBody;
    rigidbody->setWeight(200);
    rigidbody->isDynamic();
    rigidbody->setFriction(0.3);
    rigidbody->gravityMultiplier(5);
    rigidbody->setFixedRot(true);
    addComponent(rigidbody);
    
    gme::BoxCollider *collider = new gme::BoxCollider;
    collider->setSize(37*3,18*3);
    collider->addFilterTag("enemy");
    addComponent(collider);
    
}


