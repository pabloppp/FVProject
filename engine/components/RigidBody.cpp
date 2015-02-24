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
        speed.x += weight*gravityDirection.normalized().x*gravityForce*100*deltaTime;
        speed.y += weight*gravityDirection.normalized().y*gravityForce*100*deltaTime;
    }  
    
    float frictionAngular = 0;
    if(friction != 0){   
        frictionV.x = speed.x*friction;
        frictionV.y = speed.y*friction;
        frictionAngular = angularSpeed*friction;       
    }
    
    if(gameObject()!= NULL){
        Vector2 p = gameObject()->getTransform()->getPosition();
        gameObject()->getTransform()->position.x += speed.x*deltaTime;
        gameObject()->getTransform()->position.y += speed.y*deltaTime;
        if(!fixedRotation) gameObject()->getTransform()->rotation += angularSpeed*100*deltaTime;
    }
        
    speed.x += acceleration.x-frictionV.x;
    speed.y += acceleration.y-frictionV.y;
    angularSpeed += angularAcceleration-frictionAngular;
   
    //p->x += speed.x;
    //p->y += speed.y;
}

void RigidBody::push(Vector2 vector){
    speed.x += vector.x*100;
    speed.y += vector.y*100;
}

void RigidBody::push(Vector2 direction, float force){
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

