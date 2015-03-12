#include "PlayerMovement.hpp"

void PlayerMovement::setup() {

}

void PlayerMovement::update() {
    
    float deltaTime = gme::Game::deltaTime.asSeconds();
    
    if(getRigidBody() == NULL) return;
    
    float speedX = getRigidBody()->getSpeed().x;
    float speedY = getRigidBody()->getSpeed().y;
    
    if(gme::Keyboard::isKeyPressed(leftKey) && !hitWallLeft){
        if(gme::Keyboard::isKeyPressed(downKey))
            getRigidBody()->setSpeed(-(walkingSpeed/2.f)*deltaTime, speedY);
        else 
            getRigidBody()->setSpeed(-walkingSpeed*deltaTime, speedY);
        if(!flipped){
            getTransform()->resize(gme::Vector2(-1,1));
            flipped = true;
        }
    }
    else if(gme::Keyboard::isKeyPressed(rightKey) && !hitWallRight){
        if(gme::Keyboard::isKeyPressed(downKey))
            getRigidBody()->setSpeed((walkingSpeed/2.f)*deltaTime, speedY);
        else 
            getRigidBody()->setSpeed(walkingSpeed*deltaTime, speedY);
        if(flipped){
            getTransform()->resize(gme::Vector2(-1,1));
            flipped = false;
        }
    }
    else{
        getRigidBody()->setSpeed(0, speedY);
    }
    
    if(gme::Keyboard::isKeyPressed(jumpKey) && grounded && !jumped){
        if(gme::Keyboard::isKeyPressed(downKey))
            getRigidBody()->pushImmediate(gme::Vector2(0,-1), (jumpForce/2.f)*deltaTime);
        else 
            getRigidBody()->pushImmediate(gme::Vector2(0,-1), jumpForce*deltaTime);
        jumped = true;
    }
    else if(jumped && !gme::Keyboard::isKeyPressed(jumpKey)){
        jumped = false;
    }
    
    animate();
    
    grounded = false;
    hitWallLeft = false;
    hitWallRight = false;
}

void PlayerMovement::onCollision(gme::Collider* c) {
    gme::Vector2 relativePosition = getCollider()->getRelativePosition(c);
    if(c->gameObject()->hasTag("limit") || c->gameObject()->hasTag("floor")){
        
        if(relativePosition.y == -1){ //si golpea el suelo
            grounded = true;
        }
        
        //si golpea las paredes
        if(relativePosition.x == 1){
            hitWallLeft = true;
        }
        else if(relativePosition.x == -1){
            hitWallRight = true;
        }

    }
}

void PlayerMovement::animate() {
    if(grounded && getRigidBody()->getSpeed().x != 0){
        
        if(animClock.currentTime().asSeconds() > 1.0f/walkFPS){
            animClock.restart();
            walkFrameCount++;
            if(walkFrameCount >= 8) walkFrameCount = 0;
            if(gme::Keyboard::isKeyPressed(downKey)) 
                getRenderer()->setFrame(gme::Vector2(8+walkFrameCount,1));
            else 
                getRenderer()->setFrame(gme::Vector2(walkFrameCount,1));
        }
        
    }
    else if(grounded && getRigidBody()->getSpeed().x == 0){
        if(gme::Keyboard::isKeyPressed(downKey)){
           getRenderer()->setFrame(gme::Vector2(20,1)); 
        }
        else if(gme::Keyboard::isKeyPressed(upKey)){
           getRenderer()->setFrame(gme::Vector2(21,3)); 
        }
        else{
            getRenderer()->setFrame(gme::Vector2(0,0));
        } 
        walkFrameCount = 0;
    }
    else if(!grounded){
        if(getRigidBody()->getSpeed().y < -10){
            getRenderer()->setFrame(gme::Vector2(1,0));
        }
        else if(getRigidBody()->getSpeed().y > 10){
            getRenderer()->setFrame(gme::Vector2(3,0));
        }
        else{
            getRenderer()->setFrame(gme::Vector2(2,0));
        }
    }
}


PlayerMovement::~PlayerMovement() {

}


