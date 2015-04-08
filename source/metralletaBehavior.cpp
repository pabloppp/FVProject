#include "metralletaBehavior.hpp"
#include "pistolaBullet.hpp"

void metralletaBehavior::setup() {
    getRenderer()->setTexture("gun");
    speedBullet = 25.f;

}

void metralletaBehavior::update() {
    if(gme::Keyboard::isKeyPressed(ShotKey)){
        animator.animate();
        if(gme::Keyboard::isKeyPressed(keyUp) ){
            direction = 0;
            shoot(direction);
        }
        else if(gme::Keyboard::isKeyPressed(keyDown)){
            direction = 2;
            shoot(direction);
        } 
        else if(gme::Keyboard::isKeyPressed(keyLeft)){
            direction = 3;
            shoot(direction);
        }
        else if(gme::Keyboard::isKeyPressed(keyRight)) {
            direction = 1;
            shoot(direction);
        }
        else if(!gme::Keyboard::isKeyPressed(keyRight) &&
                !gme::Keyboard::isKeyPressed(keyLeft) &&
                !gme::Keyboard::isKeyPressed(keyDown) &&
                !gme::Keyboard::isKeyPressed(keyUp)){
            shoot(direction);
        }
    }
    else animator.restart();
  
}

void metralletaBehavior::shoot(int d){
    float timePassed = 0.f;
    directionSp = d;
    animator.at(timePassed, [](void* ctx) {
       metralletaBehavior *q = static_cast<metralletaBehavior*> (ctx);
       gme::GameObject *bulletx = new pistolaBullet("bullet");
       q->instantiate(bulletx);
       bulletx->getTransform()->setPosition(gme::Vector2(500,350));
       switch(q->directionSp){
            case 0:
                bulletx->getTransform()->setRotation(90);
                bulletx->getRigidBody()->setSpeed(0.0, -q->speedBullet);
                break;
            case 1:
                bulletx->getRigidBody()->setSpeed(q->speedBullet,0.0);
                break;
            case 2:
                bulletx->getTransform()->setRotation(90);
                bulletx->getRigidBody()->setSpeed(0.0,q->speedBullet);
                break;
            case 3:
                bulletx->getRigidBody()->setSpeed(-q->speedBullet,0.0);
                break;
        }
    }, this);
    timePassed += cadency;
       
   
            
}

metralletaBehavior::~metralletaBehavior() {

}



