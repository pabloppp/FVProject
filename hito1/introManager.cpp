#include "introManager.hpp"
#include "animationTest.hpp"

void introManager::setup() {
    getRenderer()->setTexture("playerTexture");
    getRenderer()->setSize(gme::Vector2(32,32));
    getRenderer()->setCenter(gme::Vector2(0.5, 0.7));
    getTransform()->scale = gme::Vector2(3,3);
    gme::RigidBody *rigidbody = new gme::RigidBody;
    rigidbody->setWeight(10);
    rigidbody->isDynamic();
    rigidbody->gravityMultiplier(5);
    rigidbody->setFixedRot(true);
    addComponent(rigidbody);
    
    gme::BoxCollider *collider = new gme::BoxCollider;
    collider->setSize(15*3,19*3);
    addComponent(collider);
    
    addComponent(new animationTest);
}