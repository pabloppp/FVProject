#include "pistolaBehavior.hpp"
#include "pistolaBullet.hpp"
#include "PlayerMovement.hpp"

void pistolaBehavior::setup() {
    getRenderer()->setTexture("gun");
    shooting = false;
    speedBullet = 25.f;
    
    direction = 1;

    ShotKey = ((PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>()))->weaponKey;
    keyUp = ((PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>()))->upKey;
    keyDown = ((PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>()))->downKey;
    keyLeft = ((PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>()))->leftKey;
    keyRight = ((PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>()))->rightKey;
}

void pistolaBehavior::update() {
    verticalDirection = -1;
    
    if(!isActive()) return;
    
    if(gme::Keyboard::isKeyPressed(keyUp)){
        verticalDirection = 0;
    }
    else if(gme::Keyboard::isKeyPressed(keyDown)){
        verticalDirection = 2;
    }
    else verticalDirection = -1;
    
    if(gme::Keyboard::isKeyPressed(keyLeft)){
        direction = 3;
    }
    else if(gme::Keyboard::isKeyPressed(keyRight)) {
        direction = 1;
    }
            
    if(gme::Keyboard::isKeyPressed(ShotKey) && !shooting){
        shooting = true;
            
        if(verticalDirection != -1) shoot(verticalDirection);
        else shoot(direction);
    } 
    else if(!gme::Keyboard::isKeyPressed(ShotKey) && shooting){ 
        shooting = false;
    }
  
}

void pistolaBehavior::shoot(int d){
    if(clock.currentTime().asSeconds()>0.2){
        gme::GameObject *bulletx = new pistolaBullet("bullet");
        instantiate(bulletx);   

        bulletx->getTransform()->setPosition(gme::Vector2(getTransform()->getPosition().x,getTransform()->getPosition().y-30));    
        switch(d){
            case 0:
                bulletx->getTransform()->setRotation(90);
                bulletx->getRigidBody()->setSpeed(0.0, -speedBullet);
                break;
            case 1:
                bulletx->getRigidBody()->setSpeed(speedBullet,0.0);
                break;
            case 2:
                bulletx->getTransform()->setRotation(90);
                bulletx->getRigidBody()->setSpeed(0.0,speedBullet);
                break;
            case 3:
                bulletx->getRigidBody()->setSpeed(-speedBullet,0.0);
                break;
        }
        clock.restart();
    }             
}

pistolaBehavior::~pistolaBehavior() {

}


