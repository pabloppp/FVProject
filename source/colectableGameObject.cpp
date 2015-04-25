#include "colectableGameObject.hpp"
#include "ColectableScript.hpp"
#include "DestroyScript.hpp"

void colectableGameObject::setup() {
    addTag("colectable");
    
    getRenderer()->setTexture("pipa");
    getRenderer()->setSize(gme::Vector2(32,32));
    getTransform()->scale = gme::Vector2(3,3);
    getRenderer()->setPivot(gme::Vector2(0.5, 1));
    
    gme::RigidBody *rb = new gme::RigidBody();
    rb->setElasticity(0);
    rb->setFixedRot(true);
    
    addComponent(rb);
    
    gme::BoxCollider *bc = new gme::BoxCollider();
    bc->addFilterTag("enemy");
    bc->addFilterTag("bullet");
    addComponent(bc);
    
    addComponent(new ColectableScript(objectType));
    addComponent(new DestroyScript);
    //addComponent(new colectableScript);
    // saddComponent(new DestroyManager);
    
    destroy = false;
    
}








