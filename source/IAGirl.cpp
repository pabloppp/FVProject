
#include "IAGirl.hpp"
#include "emptyGameObject.hpp"
#include "smallExplosion.hpp"
#include "enemy.hpp"
#include "teleportExplosion.hpp"
#include "mainGame.hpp"

void IAGirl::setup() {
    std::vector<gme::GameObject*> gm = gme::GameObject::find("manager");
    if(gm.size() > 0){
        GlobalStateManager *gsm = (GlobalStateManager*)(gm.at(0)->getComponent<GlobalStateManager*>());
        if(gsm != NULL){
            manager = gsm;
        }
    }
    
    laserShot_sound = new gme::SoundPlayer();
    laserShot_sound->setSound("laserShot");
    
    laserCarga_sound = new gme::SoundPlayer();
    laserCarga_sound->setSound("laserCarga");
    
    jetpack_sound = new gme::SoundPlayer();
    jetpack_sound->setSound("jetpack");
    jetpack_sound->setVolume(30.0);
    
    teletransport_sound = new gme::SoundPlayer();
    teletransport_sound->setSound("teletransport");
}

void IAGirl::update() {
    if(manager->isPaused()) return;
    animate();
    
    if(player && player->getTransform()->getPosition().x < getTransform()->getPosition().x){
        if(!flipped) getTransform()->setScale(gme::Vector2(-3, 3));
        flipped = true;
        
    }
    else{
        if(flipped) getTransform()->setScale(gme::Vector2(3, 3));
        flipped = false;
    }
    
    //ESTADOS
    //0:random,  1: intenta golpear, 2: intenta disparar, 3: teletransporta
    
    if(getTransform()->getPosition().x < 0){
        getTransform()->setPosition(gme::Vector2(0, getTransform()->getPosition().y));
        getRigidBody()->setSpeed(0,0);
    }
    else if(getTransform()->getPosition().x > 1584){
        getTransform()->setPosition(gme::Vector2(1584, getTransform()->getPosition().y));
        getRigidBody()->setSpeed(0,0);
    }
    
    if(getTransform()->getPosition().y < -288){
        getTransform()->setPosition(gme::Vector2(getTransform()->getPosition().x, -288));
        getRigidBody()->setSpeed(0,0);
    }
    else if(getTransform()->getPosition().y > 576){
        getTransform()->setPosition(gme::Vector2(getTransform()->getPosition().x, 576));
        getRigidBody()->setSpeed(0,0);
    }
    
    //MOVIMIENTO RANDOM
    
    if(estado == 0){
         
        if(movementClock.currentTime().asSeconds() > 1){
            
            //if(mainGame::sound)jetpack_sound->play();
            movementClock.restart();
            
            int further = 50;
            
            objectivePosition.x = getTransform()->getPosition().x - further + (rand() % further*2);
            objectivePosition.y = getTransform()->getPosition().y - further + (rand() % further*2);    
            
            while (objectivePosition.y > 576-16*3*2) objectivePosition.y -= 10;  
            
            std::cout << "nueva posicion: " << objectivePosition.x << " " << objectivePosition.y  << std::endl;
        }
        
        float speed = 10;
        
        if(objectivePosition.x > getTransform()->position.x) getRigidBody()->push(gme::Vector2(1,0), speed);
        else if(objectivePosition.x < getTransform()->position.x) getRigidBody()->push(gme::Vector2(-1,0), speed);
        
        if(objectivePosition.y > getTransform()->position.y) getRigidBody()->push(gme::Vector2(0,1), speed);
        else if(objectivePosition.y < getTransform()->position.y) getRigidBody()->push(gme::Vector2(0,-1), speed);
        
        if(stateClock.currentTime().asSeconds() > 6 || damage > 15){
            if((rand() % 100) > 50 ) estado = 1;
            else estado = 2;
            getPlayer();
            stateClock.restart();
            movementClock.restart();
            damage = 0;
        }
    }
    
    if(estado == 1){
        if(player != NULL){
            float speed = 200;
            
            objectivePosition = player->getTransform()->getPosition();
            
            if(objectivePosition.x > getTransform()->position.x) getRigidBody()->push(gme::Vector2(1,0), speed);
            else if(objectivePosition.x < getTransform()->position.x) getRigidBody()->push(gme::Vector2(-1,0), speed);
        
            if(objectivePosition.y > getTransform()->position.y) getRigidBody()->push(gme::Vector2(0,1), speed);
            else if(objectivePosition.y < getTransform()->position.y) getRigidBody()->push(gme::Vector2(0,-1), speed);
        }
        
        if(damage > 7){
            estado = 3;
            stateClock.restart();
        }
        
        if(stateClock.currentTime().asSeconds() > 6){
            if((rand() % 100) > 25 ) estado = 0;
            else estado = 2;
            getPlayer();
            stateClock.restart();
            movementClock.restart();
            damage = 0;
        }
    }
    
    if(estado == 2){
        if(player != NULL){
            float speed = 30;
            objectivePosition = player->getTransform()->getPosition();
            if(objectivePosition.y > getTransform()->position.y) getRigidBody()->push(gme::Vector2(0,1), speed);
            else if(objectivePosition.y < getTransform()->position.y) getRigidBody()->push(gme::Vector2(0,-1), speed);
        }
        
        if(movementClock.currentTime().asSeconds() > 4){
            movementClock.restart();
            shootClock.restart();
            disparando = true;
        }
        
        if(!cargando && movementClock.currentTime().asSeconds() > 3){
           cargando = true;
           std::cout << "cargando"<< std::endl;
           //SONIDO DE CARGA
           if(mainGame::sound)laserCarga_sound->play();
           laserCarga_sound->setVolume(100.0);
        }
        
        if(disparando){
            if(shootClock.currentTime().asSeconds() > 0.1){
                if(mainGame::sound)laserShot_sound->play();
                std::cout << "bang " << disparos << std::endl;
                disparos++;
                shootClock.restart();
            }
            if(disparos >= 4){
                disparos = 0;
                disparando = false;
                cargando = false;
            }
        }
        
        if(damage > 7){
            estado = 3;
            stateClock.restart();
        }
        
        if(stateClock.currentTime().asSeconds() > 15){
            if((rand() % 100) > 80 ) estado = 0;
            else estado = 1;
            getPlayer();
            stateClock.restart();
            movementClock.restart();
            damage = 0;
        }
    }
    
    if(estado == 3){
        if(stateClock.currentTime().asSeconds() > 3){
            teleport();
        }
    }
    
}

void IAGirl::shoot() {
    
}

void IAGirl::teleport() {
    
    //SONIDO TELETRANSPORTE
    
    if(mainGame::sound)teletransport_sound->play();
    
    emptyGameObject *explosion = new emptyGameObject("smallboom");
    explosion->addComponent(new teleportExplosion());
    explosion->getTransform()->setPosition(getTransform()->getPosition());
    instantiate(explosion);
    estado = 0;
    damage = 0;
    stateClock.restart();
    movementClock.restart();
    
    for(int i=0;i<3;i++){
        enemy *e = new enemy("enemy");
        e->getTransform()->setPosition(gme::Vector2(getTransform()->getPosition().x-30*3+(rand()%(30*3)), getTransform()->getPosition().y-16*3));
        instantiate(e);
    }
    
    getTransform()->setPosition(gme::Vector2(rand()%1584, -288 + (rand() % (576 + 288)) ));
}



void IAGirl::animate() {

}

void IAGirl::getPlayer() {
    std::vector<gme::GameObject*> players = gme::GameObject::findWithTag("player");
    int probability = 100/players.size();
    if(rand() % 100 < probability) player = players.at(0);
    else player = players.at(1);
}


void IAGirl::onCollision(gme::Collider* c) {

}

void IAGirl::onMessage(std::string m, float v) {
    if(m.compare("damage")){
        damage += v;
    }
}

IAGirl::~IAGirl() {

}




