
#include "IAGirl.hpp"
#include "emptyGameObject.hpp"
#include "smallExplosion.hpp"
#include "enemy.hpp"
#include "teleportExplosion.hpp"
#include "enemyBullet.hpp"
#include "mainGame.hpp"
#include "defaultParticle.hpp"
#include "sprayParticleScript.hpp"

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
    if(gm.size() > 0){
        GlobalStateManager *gsm = (GlobalStateManager*)(gm.at(0)->getComponent<GlobalStateManager*>());
        if(gsm != NULL){
            stateManager = gsm;
        }
    }
}

void IAGirl::update() {
    if(manager->isPaused()) return;
    animate();
    if(life <= 0){
        stateManager->bossKilled = true;
        life = 0;
    }
    
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
            objectivePosition.y -= 8*3;
            
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
            objectivePosition.y -= 8*3;
            
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
                if(flipped) shoot(2);
                else shoot(0);
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

void IAGirl::shoot(int dir) {
        emptyGameObject *bullet = new emptyGameObject("enemy_shoot");
        enemyBullet *eb = new enemyBullet();

        bullet->addComponent(eb);
        bullet->getTransform()->setPosition(getTransform()->getPosition());
        
        gme::RigidBody *rb = new gme::RigidBody();
        rb->isDynamic();
        rb->setElasticity(0);
        rb->setFriction(0);
        rb->setWeight(0);
        rb->gravityMultiplier(0);
        
        if(dir == 0){
            rb->setSpeed(30, 0);
        }
        else if(dir == 1){
            bullet->getTransform()->setRotation(90);
            rb->setSpeed(0, -30);
        }
        else if(dir == 2){
            bullet->getTransform()->setRotation(180);
            rb->setSpeed(-30, 0);
        }
        else if(dir == 3){
            bullet->getTransform()->setRotation(270);
            rb->setSpeed(0, 30);
        }

        bullet->addComponent(rb);

        gme::BoxCollider *col = new gme::BoxCollider();
        col->isTrigger(true);
        col->setSize(8*3, 8*3);

        bullet->addComponent(col);
        
        instantiate(bullet);
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
    if(c->gameObject()->hasTag("player")){
        c->gameObject()->sendMessage("damage", 10);
    }
}

void IAGirl::onMessage(std::string m, float v) {
    if(m.compare("damage")){
        damage += v;
        life -= v;
        explode(3,10, 50, 150);
    }
    
}

void IAGirl::explode(int min, int max, float forcemin, float forcemax) {
    if(mainGame::particles == 0) return;
    else if(mainGame::particles == 1){
        max /= 4.0;
        min /= 4.0;
    } 
    int cantidad = (rand() % (max-min)) + min;
    
    gme::Vector2 pos = getTransform()->getPositionRelative();
    for(int i=0;i<cantidad;i++){
        float dirX = ( (rand() % 200) - 100 ) / 100.f;
        float dirY = ( (rand() % 200) - 100 ) / 100.f;
        int force = (rand() % (int)(forcemax-forcemin)) + forcemin;
        defaultParticle *particle = new defaultParticle("blood"); 
        particle->startingPosition = pos;
        instantiate(particle);
        particle->getTransform()->setPosition(pos);
        
        ((sprayParticleScript*)(particle->getComponent<sprayParticleScript*>()))->sticky = true;
        
        particle->getRenderer()->setColor(255,0,0);
        particle->getRigidBody()->pushImmediate(gme::Vector2(dirX, dirY), force);
                
    }
}

void IAGirl::onGui() {
    gme::GUI::backgroundColor = gme::GUI::Color(0,0,0,150);
    gme::GUI::box(gme::Vector2(1024/2, 63), gme::Vector2(3*72, 3*4), gme::GUI::Origin::Center);
    
    gme::GUI::backgroundColor = gme::GUI::Color(0,200,0,100);
    
    gme::GUI::box(gme::Vector2(1024/2 - 3*35 , 63), gme::Vector2(3*70*(1.0f*life/maxLife) , 3*2), gme::GUI::Origin::CenterLeft);
    
}


IAGirl::~IAGirl() {

}




