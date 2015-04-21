#include "pistolaBehavior.hpp"
#include "pistolaBullet.hpp"

void pistolaBehavior::setup() {
    getRenderer()->setTexture("gun");
    shooting = false;
    speedBullet = 25.f;

}

void pistolaBehavior::update() {
    if(gme::Keyboard::isKeyPressed(ShotKey) && !shooting){
        shooting = true;
        
        if(gme::Keyboard::isKeyPressed(keyUp) && shooting){
            direction = 0;
            shoot(direction);
        }
        else if(gme::Keyboard::isKeyPressed(keyDown) && shooting){
            direction = 2;
            shoot(direction);

        } 
        else if(gme::Keyboard::isKeyPressed(keyLeft) && shooting){
            direction = 3;
            shoot(direction);
        }
        else if(gme::Keyboard::isKeyPressed(keyRight) && shooting) {
            direction = 1;
            shoot(direction);
        }
        else if(!gme::Keyboard::isKeyPressed(keyRight) &&
                !gme::Keyboard::isKeyPressed(keyLeft) &&
                !gme::Keyboard::isKeyPressed(keyDown) &&
                !gme::Keyboard::isKeyPressed(keyUp) && shooting){
            shoot(direction);
        }
    } 
    else if(!gme::Keyboard::isKeyPressed(ShotKey) && shooting){ 
        shooting = false;
    }
  
}

void pistolaBehavior::shoot(int d){
    gme::GameObject *bulletx = new pistolaBullet("bullet");
    instantiate(bulletx);   
    
    bulletx->getTransform()->setPosition(gme::Vector2(500,350));    
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
                 
}

pistolaBehavior::~pistolaBehavior() {

}


