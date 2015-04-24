#include "sprayParticleScript.hpp"

void sprayParticleScript::setup() {
    
    //SETUPS
    minDuration = 1;
    maxDuration = 5;
    
    duration = (rand() % (maxDuration-minDuration)) + minDuration;
    
    sticky = false;
   
}

void sprayParticleScript::update() {
    if(lifeClock.currentTime().asSeconds() > duration) destroyGameObject(gameObject());
}

sprayParticleScript::~sprayParticleScript() {

}

void sprayParticleScript::onCollision(gme::Collider* c) {
    gme::Vector2 relativePosition = getCollider()->getRelativePosition(c);
    if(sticky && relativePosition.y == 1 && relativePosition.x == 0){
        getRigidBody()->gravityMultiplier(0);
        getRigidBody()->setSpeed(0,0);
    }
}



