#include <math.h>

#include "RigidBody.hpp"
#include "Transform.hpp"
#include "../GameObject.hpp"
#include "../Game.hpp"
#include "BoxCollider.hpp"

#define SCALE 30.0f
#define PI  3.14159265 

using namespace gme;

RigidBody::RigidBody() : Component::Component(){
    weight = 1;
    friction = 0.1;
    
    b2def.position.Set(0.0f, 0.0f);
    b2def.type = b2_dynamicBody;

    b2body = Game::getCurrentScene()->boxWorld->CreateBody(&b2def);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    fixtureDef.density = weight;
    fixtureDef.shape = &dynamicBox; 
    fixtureDef.isSensor = true;
    fixtureDef.filter.maskBits = 0x0000;
    b2body->CreateFixture(&fixtureDef);
    
    fixedRotation = false;
}

RigidBody::~RigidBody() {
    Game::getCurrentScene()->boxWorld->DestroyBody(b2body);
}


void RigidBody::setup(){
    if(gameObject() != NULL && gameObject()->getTransform() != NULL){
        b2def.position.Set(gameObject()->getTransform()->getPosition().x/SCALE, gameObject()->getTransform()->getPosition().y/SCALE);
        //b2body = Game::getCurrentScene()->boxWorld->CreateBody(&b2def);
    }
}

void RigidBody::update(){
    if(gameObject() != NULL && gameObject()->getTransform() != NULL){
        b2body->SetTransform(b2Vec2(gameObject()->getTransform()->getPosition().x/SCALE, 
                gameObject()->getTransform()->getPosition().y/SCALE), 
                gameObject()->getTransform()->getRotation()*PI/180.f);
    }
    
    b2body->SetLinearDamping(friction*10);
    
    b2body->SetAngularDamping(friction*10);
}

void RigidBody::updatep(){
    if(gameObject()!= NULL && gameObject()->getTransform() != NULL){
        Vector2 parentDisp(0,0);
        float parentRot = 0;
        if(gameObject()->getParent() != NULL && gameObject()->getParent()->getTransform() != NULL){
            parentDisp = gameObject()->getParent()->getTransform()->getPosition();
            parentRot = gameObject()->getParent()->getTransform()->getRotation();
        }
        gameObject()->getTransform()->position.x = b2body->GetPosition().x*SCALE - parentDisp.x;

        gameObject()->getTransform()->position.y = b2body->GetPosition().y*SCALE - parentDisp.y;
        
        if(!fixedRotation) gameObject()->getTransform()->rotation = b2body->GetTransform().q.GetAngle()*180.f/PI - parentRot;
    }
}

void RigidBody::setSpeed(float x, float y) {
    b2body->SetLinearVelocity(b2Vec2(x, y));
}

void RigidBody::setSpeed(Vector2 direction, float force){
    Vector2 vector = direction.normalized();
    vector.x *= force;
    vector.y *= force;
    setSpeed(vector.x, vector.y);
}

void RigidBody::setAngularSpeed(float f) {

}



void RigidBody::push(Vector2 vector){
    b2body->ApplyForceToCenter(b2Vec2(vector.x, vector.y), true);
}

void RigidBody::push(Vector2 direction, float force){
    Vector2 vector = direction.normalized();
    vector.x *= force;
    vector.y *= force;
    push(vector);
}

void RigidBody::pushImmediate(Vector2 direction, float force) {
    Vector2 vector = direction.normalized();
    vector.x *= force;
    vector.y *= force;
    b2body->ApplyLinearImpulse(b2Vec2(vector.x, vector.y), b2body->GetTransform().p, true);
}


void RigidBody::rotateImmediate(float force) {
    b2body->ApplyAngularImpulse(force, true);
    //b2body->ApplyTorque(20, true);
}

void RigidBody::rotate(float force) {
    b2body->ApplyTorque(force, true);
}



void RigidBody::setGravity(bool g){
    if(g){
        b2body->SetGravityScale(1);
        b2body->SetAwake(true);
    }
    else b2body->SetGravityScale(0);
}

void RigidBody::gravityMultiplier(float f) {
    b2body->SetGravityScale(f);
}


bool RigidBody::hasGravity(){
    if(b2body->GetGravityScale() != 0) return true;
    else return false;
}

void RigidBody::onCollision(Collider* c) {
    
}

void RigidBody::isKinematic() {
    b2body->SetType(b2_kinematicBody);
}

void RigidBody::isDynamic() {
    b2body->SetType(b2_dynamicBody); 
}

void RigidBody::isStatic() {
    b2body->SetType(b2_staticBody);
}


void RigidBody::setFixedRot(bool b) {
    fixedRotation = b;
    b2body->SetFixedRotation(b);
}

void RigidBody::setFriction(float f) {
    friction = f;
    for (b2Fixture *ce = b2body->GetFixtureList(); ce != NULL; ce = ce->GetNext())
    {
        ce->SetFriction(f);
    }
}


void RigidBody::setWeight(float f) {
    weight = f;
    for (b2Fixture *ce = b2body->GetFixtureList(); ce != NULL; ce = ce->GetNext())
    {
        ce->SetDensity(f);
    }
}

void RigidBody::setElasticity(float f) {
    elasticity = f;
    for (b2Fixture *ce = b2body->GetFixtureList(); ce != NULL; ce = ce->GetNext())
    {
        ce->SetRestitution(elasticity);
    }
}


float RigidBody::getElasticity() {
    return elasticity;
}

float RigidBody::getFriction() {
    return friction;
}

float RigidBody::getWeight() {
    return weight;
}

float RigidBody::getAngularSpeed() {
    return b2body->GetAngularVelocity();
}

Vector2 RigidBody::getSpeed() {
    return Vector2(b2body->GetLinearVelocity().x, b2body->GetLinearVelocity().y); 
}





