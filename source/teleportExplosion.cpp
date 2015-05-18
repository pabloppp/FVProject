#include "teleportExplosion.hpp"

void teleportExplosion::setup() {
    getRenderer()->setTexture("explosion_teleport");
    getRenderer()->setSize( gme::Vector2(32,32) );
    getTransform()->setScale(gme::Vector2(3,3));
    framecount = 0;
}

void teleportExplosion::update() {
    if(reloj.currentTime().asSeconds() > 0.04){
        framecount++;
        if(framecount < 6) getRenderer()->setFrame(gme::Vector2(framecount, 0));
        else destroyGameObject(gameObject());
        reloj.restart();
    }
}

teleportExplosion::~teleportExplosion() {
}

