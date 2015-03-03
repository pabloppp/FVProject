#include <math.h>

#include "RigidBody.hpp"
#include "Transform.hpp"
#include "../GameObject.hpp"
#include "../Game.hpp"

using namespace gme;

RigidBody::RigidBody() : Component::Component(){
    gravity = true;
    weight = 1;
    friction = 0.05;
    speed = 0;
    angularSpeed = 0;
}

void RigidBody::setup(){
}

void RigidBody::update(){
    float deltaTime = Game::deltaTime.asSeconds();
    
    if(gravity){
        speed.x += weight*gravityDirection.normalized().x*gravityForce*deltaTime*5;
        speed.y += weight*gravityDirection.normalized().y*gravityForce*deltaTime*5;
    }  
    
    float frictionAngular = 0;
    if(friction != 0){   
        frictionV.x = speed.x*friction;
        frictionV.y = speed.y*friction;
        frictionAngular = angularSpeed*friction;       
    }
    
    if(gameObject()!= NULL){
        Vector2 p = gameObject()->getTransform()->getPosition();
        gameObject()->getTransform()->position.x += speed.x*deltaTime*10;
        gameObject()->getTransform()->position.y += speed.y*deltaTime*10;
        if(!fixedRotation) gameObject()->getTransform()->rotation += angularSpeed*deltaTime*10;
    }
        
    speed.x += acceleration.x*deltaTime-frictionV.x;
    speed.y += acceleration.y*deltaTime-frictionV.y;
    angularSpeed += angularAcceleration*deltaTime-frictionAngular;
   
    //p->x += speed.x;
    //p->y += speed.y;
}

void RigidBody::push(Vector2 vector){
    float deltaTime = Game::deltaTime.asSeconds();
    speed.x += vector.x;
    speed.y += vector.y;
}

void RigidBody::push(Vector2 direction, float force){
    float deltaTime = Game::deltaTime.asSeconds();
    Vector2 vector = direction.normalized();
    vector.x *= force;
    vector.y *= force;
    push(vector);
}

void RigidBody::setGravity(bool g){
    gravity = g;
}

bool RigidBody::hasGravity(){
    return gravity;
}

float RigidBody::gravityForce = 9.81;

Vector2 RigidBody::gravityDirection(0,1);

