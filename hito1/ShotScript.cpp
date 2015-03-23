#include "ShotScript.hpp"
#include "bullet.hpp"
#include "BulletScript.hpp"
#include "player.hpp"
#include "PlayerMovement.hpp"

void ShotScript::setup(){
    disparado = false;
    arma = 1;
    bool cambio = false;
}

void ShotScript::update(){
    PlayerMovement *pm = (PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>());
    
    if(gme::Keyboard::isKeyPressed(pm->weaponKey) && !disparado){
        disparado = true;
        std:: cout << "Disparo" << std::endl;
        
        gme::GameObject *bulletx = new bullet("bullet");
        instantiate(bulletx); //anyade la bala al juego
        BulletScript *ss =  (BulletScript*)(bulletx->getComponent<BulletScript*>());
        
        
        if(gme::Keyboard::isKeyPressed(pm->upKey)) ss->direccion = 1;
        else if(gme::Keyboard::isKeyPressed(pm->downKey)) ss->direccion = 3;
        else if(!pm->flipped) ss->direccion = 2;
        
        bulletx->getTransform()->setPosition(this->getTransform()->getPosition());
        
    }
    else if(!gme::Keyboard::isKeyPressed(pm->weaponKey) && disparado){
        disparado = false;
    }
    
    if(gme::Keyboard::isKeyPressed(pm->changeWeapon) && !cambio){
        
        cambio = true;
        
        if(arma==1){
           getRenderer()->setTexture("weaponTexture2");
           //getRenderer()->setSize(gme::Vector2(32,32));
           //getTransform()->scale = gme::Vector2(0.3,0.3); 
           
           arma=2;
        }else if(arma==2){
            getRenderer()->setTexture("weaponTexture");
            arma=1;
        }
        
    }else if(!gme::Keyboard::isKeyPressed(pm->changeWeapon) && cambio){
        cambio=false;
    }
    
}

ShotScript::~ShotScript(){
    
}

