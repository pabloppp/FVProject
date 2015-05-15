#include "escopetaBehavior.hpp"
#include "escopetaBullet.hpp"
#include "PlayerMovement.hpp"

void escopetaBehavior::setup() {
    getRenderer()->setTexture("gun");
    speedBullet = 32.f;
    shooting = false;
    direction = 1;
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
    std::vector<gme::GameObject*> gm = gme::GameObject::find("manager");
    if(gm.size() > 0){
        GlobalStateManager *gsm = (GlobalStateManager*)(gm.at(0)->getComponent<GlobalStateManager*>());
        if(gsm != NULL){
            manager = gsm;
        }
    }
}

void escopetaBehavior::update() {
    if(manager->isPaused()) return;
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
    
    if(gme::Keyboard::isKeyPressed(ShotKey) && !shooting ){
        shooting = true;
        if(verticalDirection != -1) shoot(verticalDirection);
        else shoot(direction);
    } 
    else if(!gme::Keyboard::isKeyPressed(ShotKey) && shooting){ 
        shooting = false;
    }
}

void escopetaBehavior::shoot(int d) {
    if(clock.currentTime().asSeconds()>1){
        escopetaBullet *bulletx = new escopetaBullet("bullet");
        escopetaBullet *bullety = new escopetaBullet("bullet");
        escopetaBullet *bulletz = new escopetaBullet("bullet");
        if(gameObject()->getParent()->getName().compare("p2") == 0){
            bulletx->whoshoots = 2;
            bullety->whoshoots = 2;
            bulletz->whoshoots = 2;
        }
        instantiate(bulletx);   
        instantiate(bullety); 
        instantiate(bulletz); 

        bulletx->getTransform()->setPosition(gme::Vector2(getTransform()->getPosition().x,getTransform()->getPosition().y-30));    
        bullety->getTransform()->setPosition(gme::Vector2(getTransform()->getPosition().x,getTransform()->getPosition().y-30)); 
        bulletz->getTransform()->setPosition(gme::Vector2(getTransform()->getPosition().x,getTransform()->getPosition().y-30)); 
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

