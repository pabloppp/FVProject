#include "colectableGameObject.hpp"
#include "ColectableScript.hpp"
#include "LifeManager.hpp"

void colectableGameObject::setup() {
    addTag("colectable");
    
    getRenderer()->setTexture("boxes");
    getRenderer()->setSize(gme::Vector2(32,32));
    getRenderer()->setFrame("ani_CaidaPaquete_0");
    getTransform()->scale = gme::Vector2(3,3);
    getRenderer()->setPivot(gme::Vector2(0.5, 0.825));
    
    gme::RigidBody *rb = new gme::RigidBody();
    rb->setElasticity(0);
    rb->setFixedRot(true);
    
    addComponent(rb);
    
    gme::BoxCollider *bc = new gme::BoxCollider();
    bc->addFilterTag("enemy");
    bc->addFilterTag("colectable");
   
   
    addComponent(bc);
    addComponent(new ColectableScript(objectType));
    
}










