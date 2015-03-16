#include "ShotScript.hpp"
#include "bullet.hpp"

void ShotScript::setup(){
    
}

void ShotScript::update(){
    
    if(gme::Keyboard::isKeyPressed(ShotKey)){
        std:: cout << "Disparo" << std::endl;
        
        gme::GameObject *bulletx = new bullet("bullet");
        instantiate(bulletx); //anyade la bala al juego
        bulletx->getTransform()->setPosition(this->getTransform()->getPosition());
        
        /*Como hacer para que dispare en la direccion en la que se ha quedado*/
    }
    
}

ShotScript::~ShotScript(){
    
}

