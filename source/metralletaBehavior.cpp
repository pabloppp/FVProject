#include "metralletaBehavior.hpp"
#include "metralletaBullet.hpp"

void metralletaBehavior::setup() {
    getRenderer()->setTexture("gun");
    speedBullet = 25.f;
    direction = 1;
    numBullets = 100;
    recargando = false;
    std::vector<gme::GameObject*> *objects = gme::Game::getCurrentScene()->getGameObjects();
    for(int i=0;i<objects->size();i++){
        if(objects->at(i) == gameObject()){
            objects->erase(objects->begin()+i);
            objects->push_back(gameObject());
            break;
        }
    }
    
    ShotKey = ((PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>()))->weaponKey;
    keyUp = ((PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>()))->upKey;
    keyDown = ((PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>()))->downKey;
    keyLeft = ((PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>()))->leftKey;
    keyRight = ((PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>()))->rightKey;
}

void metralletaBehavior::update() {
    if(numBullets <= 0 && !recargando){
        recargando = true;
        return;
    }
    if(recargando){
        if(clock.currentTime().asSeconds() > 0.05){
            clock.restart();
            numBullets = numBullets + 4;
        } 
        if(numBullets >= 100) recargando = false;
        return;
    }
    
    
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
    
    if(gme::Keyboard::isKeyPressed(ShotKey) && !recargando){
        animator.animate();
        if(verticalDirection != -1) shoot(verticalDirection);
        else shoot(direction);
    }
    else if(!gme::Keyboard::isKeyPressed(ShotKey)) animator.restart();
  
}

void metralletaBehavior::shoot(int d){
    
    float timePassed = 0.f;
    directionSp = d;
    animator.at(timePassed, [](void* ctx) {
       metralletaBehavior *q = static_cast<metralletaBehavior*> (ctx);
       gme::GameObject *bulletx = new metralletaBullet("bullet");
       q->instantiate(bulletx);
       q->numBullets--;
      

       int v1 = rand() % 10+0;
       if(q->directionSp == 1 || q->directionSp == 3){
            bulletx->getTransform()->setPosition(
                gme::Vector2(q->getTransform()->getPosition().x,
               (q->getTransform()->getPosition().y-30+v1))
            );
       }
       else if(q->directionSp == 0 || q->directionSp == 2){
            bulletx->getTransform()->setPosition(
                gme::Vector2(q->getTransform()->getPosition().x+v1,
               (q->getTransform()->getPosition().y-30))
            );
       }
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



