
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
    gme::GameObject *player = gme::GameObject::findWithTag("player_1");
    
    
    getRigidBody()->setSpeed(-6.f,0.0);
    
    float posX = getTransform()->getPosition().x;
    if(posX < 0 || posX > winSize){
        destroyGameObject(gameObject());
        std:: cout << "Destroying bullet" << std::endl;
    }
}

void BulletScript::onCollision(gme::Collider *c){
    //Colision con enemigos
}


