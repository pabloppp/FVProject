
#include "BulletScript.hpp"

BulletScript::BulletScript() {
}

BulletScript::BulletScript(const BulletScript& orig) {
}

BulletScript::~BulletScript() {
}

void BulletScript::setup(){
    winSize = gme::Game::getWindow()->getSize().x; 
}

void BulletScript::update(){
    
    //Obtener direccion jugador
    //gme::GameObject *player = gme::GameObject::findWithTag("player_1");
    
    
    if(direccion == 0) getRigidBody()->setSpeed(-6.f,0.0);
    else if(direccion == 1) getRigidBody()->setSpeed(0,-6.f);
    else if(direccion == 2) getRigidBody()->setSpeed(6.f,0.0);
    else if(direccion == 3) getRigidBody()->setSpeed(0,6.f);
    
    
    float posX = getTransform()->getPosition().x;
    if(posX < 0 || posX > winSize){
        destroyGameObject(gameObject());
        std:: cout << "Destroying bullet" << std::endl;
    }
}

void BulletScript::onCollision(gme::Collider *c){
    //Colision con enemigos
}


