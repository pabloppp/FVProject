#include "tileDestroyManager.hpp"
#include "defaultParticle.hpp"
#include "mainGame.hpp"

void tileDestroyManager::setup() {
    isHit = false;
    isHitTemp = false;
    bloque_sound = new gme::SoundPlayer();   
    bloque_sound->setSound("bloque");
    
}

void tileDestroyManager::update() {
    if(isHitTemp == false){
        isHit = false;
    }
    isHitTemp = false;
}

tileDestroyManager::~tileDestroyManager() {
    
    
}

void tileDestroyManager::onMessage(std::string m, float v) {
    if(m.compare("damage") == 0 && isHit == false){
        
        isHit = true;
        isHitTemp = true;
        hp -= v;
        if(hp <= 0){
           if(mainGame::sound) bloque_sound->play();
            explode(10,20,50,100);
            destroyGameObject(gameObject());
            
        }
        else{
            explode(3,10,25,50);
           if(mainGame::sound) bloque_sound->play();
        }
    }
}

void tileDestroyManager::explode(int min, int max, float forcemin, float forcemax) {
    
    //if(mainGame::sound)bloque_sound->play();
    
    int cantidad = (rand() % (max-min)) + min;
    
    gme::Vector2 pos = getTransform()->getPosition();
    
   
    
    pos.y += 8*3;
    
    for(int i=0;i<cantidad;i++){
        float dirX = ( (rand() % 200) - 100 ) / 100.f;
        float dirY = ( (rand() % 200) - 100 ) / 100.f;
        int force = (rand() % (int)(forcemax-forcemin)) + forcemin;
        defaultParticle *particle = new defaultParticle("blood"); 
        particle->startingPosition = pos;
        instantiate(particle);
        particle->getTransform()->setPosition(pos);
        
        if(rand() % 10 == 1){
            particle->getRenderer()->setColor(33,51,32);
            
        }
        else{
            particle->getRenderer()->setColor(103,64,40);
        }
        particle->getRigidBody()->pushImmediate(gme::Vector2(dirX, dirY), force);
    }
}


