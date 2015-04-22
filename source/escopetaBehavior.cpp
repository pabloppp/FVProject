
#include "escopetaBehavior.hpp"
#include "escopetaBullet.hpp"

void escopetaBehavior::setup() {
    getRenderer()->setTexture("gun");
    speedBullet = 25.f;
    shooting = false;
}

void escopetaBehavior::update() {
    if(gme::Keyboard::isKeyPressed(ShotKey) && !shooting ){
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

void escopetaBehavior::shoot(int d) {
    if(clock.currentTime().asSeconds()>1){
        
        gme::GameObject *bulletx = new escopetaBullet("bullet");
        gme::GameObject *bullety = new escopetaBullet("bullet");
        gme::GameObject *bulletz = new escopetaBullet("bullet");
        instantiate(bulletx);   
        instantiate(bullety); 
        instantiate(bulletz); 

        bulletx->getTransform()->setPosition(gme::Vector2(500,350));    
        bullety->getTransform()->setPosition(gme::Vector2(500,350)); 
        bulletz->getTransform()->setPosition(gme::Vector2(500,350)); 
        switch(d){
            case 0:
                bulletx->getTransform()->setRotation(79.2);
                bulletx->getRigidBody()->setSpeed(-3.0, -speedBullet);
                bullety->getTransform()->setRotation(90);
                bullety->getRigidBody()->setSpeed(0.0, -speedBullet);
                bulletz->getTransform()->setRotation(100.8);
                bulletz->getRigidBody()->setSpeed(3.0, -speedBullet);
                break;
            case 1:
                bulletx->getTransform()->setRotation(-10.8);
                bulletx->getRigidBody()->setSpeed(speedBullet,-3.0);
                bullety->getRigidBody()->setSpeed(speedBullet, 0.0);
                bulletz->getTransform()->setRotation(10.8);
                bulletz->getRigidBody()->setSpeed(speedBullet, 3.0);
                break;
            case 2:
                bulletx->getTransform()->setRotation(100.8);
                bulletx->getRigidBody()->setSpeed(3.0, speedBullet);
                bullety->getTransform()->setRotation(90);
                bullety->getRigidBody()->setSpeed(0.0, speedBullet);
                bulletz->getTransform()->setRotation(79.2);
                bulletz->getRigidBody()->setSpeed(-3.0, speedBullet);
                break;
            case 3:
                bulletx->getTransform()->setRotation(-10.8);
                bulletx->getRigidBody()->setSpeed(-speedBullet,3.0);
                bullety->getRigidBody()->setSpeed(-speedBullet, 0.0);
                bulletz->getTransform()->setRotation(10.8);
                bulletz->getRigidBody()->setSpeed(-speedBullet, -3.0);
                break;
        }
         clock.restart(); 
    }
               
  
}

escopetaBehavior::~escopetaBehavior() {
}

