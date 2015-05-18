

#include "IAexplosive.hpp"
#include "tile.hpp"
#include "sprayParticleScript.hpp"
#include "defaultParticle.hpp"
#include "emptyGameObject.hpp"
#include "bigExplosion.hpp"
#include "mainGame.hpp"

void IAexplosive::setup() {

        
    granada_sound = new gme::SoundPlayer();
    granada_sound->setSound("granada");
    
    danyoEnemigo_sound = new gme::SoundPlayer();
    danyoEnemigo_sound->setSound("danyo2");
    danyoEnemigo_sound->setVolume(30.0);
   
    explosionEnemigo_sound = new gme::SoundPlayer();
    explosionEnemigo_sound->setSound("explosionEnemigo");
}

void IAexplosive::update() {
    if(gonnaExplode){
        float glow = 255*(countdownClock.currentTime().asSeconds()/2.0);
        getRenderer()->setColor(255,255-glow,255-glow);
    }
    if(gonnaExplode && countdownClock.currentTime().asSeconds() > 1){
        if(!exploded) explode();
    }
}

void IAexplosive::onMessage(std::string m, float v) {
    if(m.compare("damage") == 0 && !gonnaExplode){
        if(mainGame::sound)danyoEnemigo_sound->play();
        gonnaExplode = true;
        countdownClock.restart();
    }
    if(m.compare("kill") == 0 && !exploded){
        
       // if(mainGame::sound)explosionEnemigo_sound->play();
        explode();
    }
    if(m.compare("iam")==0){
        iam = v;
    }
}

void IAexplosive::explode() {
    exploded = true;
    emptyGameObject *explosion = new emptyGameObject("bigboom");
    bigExplosion *be = new bigExplosion();
    if(mainGame::sound)granada_sound->play();
    be->whoami = 1;
    explosion->addComponent(be);
    explosion->getTransform()->setPosition(getTransform()->getPosition());

    gme::RigidBody *rb = new gme::RigidBody();
    rb->isDynamic();
    rb->setElasticity(0);
    rb->setFriction(0);
    rb->setWeight(0);
    rb->gravityMultiplier(0);

    explosion->addComponent(rb);

    gme::BoxCollider *col = new gme::BoxCollider();
    col->isTrigger(true);
    col->setSize(50*3, 50*3);

    explosion->addComponent(col);

    instantiate(explosion);
        
}

