#include "granada.hpp"
#include "granadaBehavior.hpp"

void granada::setup() {
    addTag("bullet"); 
    
    getRenderer()->setTexture("grenade");
    getRenderer()->setSize(gme::Vector2(16,16));
    getTransform()->resize(gme::Vector2(3,3));
    
    gme::RigidBody *rb = new gme::RigidBody();
    rb->isDynamic();
    rb->setElasticity(0.6);
    rb->setFriction(0.1);
    rb->setWeight(30);
    rb->gravityMultiplier(3);
    
    if(direction == 0){
        rb->pushImmediate(gme::Vector2(0.7,-0.5), 90);
        rb->rotateImmediate(50);
    }
    else{
        rb->pushImmediate(gme::Vector2(-0.7,-0.5), 90);
        rb->rotateImmediate(-50);
    }
    
    addComponent(rb);
    
    gme::BoxCollider *col = new gme::BoxCollider();
    col->setSize(16,16);
    col->addFilterTag("player");
    addComponent(col);
    
    granadaBehavior *gb = new granadaBehavior();
    gb->whoami = whoshoots;
    addComponent(gb);
    
}


