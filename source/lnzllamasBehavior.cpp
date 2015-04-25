
#include "lnzllamasBehavior.hpp"
#include "llamasBullet.hpp"


void lnzllamasBehavior::setup() {
    getRenderer()->setTexture("lanzallamas");
    getRenderer()->setSize(gme::Vector2(64,64)); //scale en weapon
    speedBullet = 8.f;
}

void lnzllamasBehavior::update() {
    if(gme::Keyboard::isKeyPressed(ShotKey)){
        animator.animate();
        if(gme::Keyboard::isKeyPressed(keyUp)){
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
    else if(!gme::Keyboard::isKeyPressed(ShotKey)){ 
        animator.restart();
    }
}

void lnzllamasBehavior::shoot(int d) {

    float timePassed = 0.04f;
    directionSp = d;
   
    animator.at(timePassed, [](void* ctx) {
       lnzllamasBehavior *q = static_cast<lnzllamasBehavior*> (ctx);
       gme::GameObject *bulletx = new llamasBullet("bullet");
       q->instantiate(bulletx);
       int v1 = rand() % 5+348;
       bulletx->getTransform()->setPosition(gme::Vector2(440,v1));
       
       switch(q->directionSp){
            case 0:
                bulletx->getRigidBody()->setSpeed(0.0, -q->speedBullet);
                break;
            case 1:
                bulletx->getRigidBody()->setSpeed(q->speedBullet,0.0);
                break;
            case 2:
                bulletx->getRigidBody()->setSpeed(0.0,q->speedBullet);
                break;
            case 3:
                bulletx->getRigidBody()->setSpeed(-q->speedBullet,0.0);
                break;
        }
    }, this);
    timePassed += cadency;
  
}

lnzllamasBehavior::~lnzllamasBehavior() {

}





