/* 
 * File:   smallExplosion.cpp
 * Author: pablopernias
 * 
 * Created on 15 de mayo de 2015, 11:20
 */

#include "smallExplosion.hpp"

void smallExplosion::setup() {
    getRenderer()->setTexture("explosion_small");
    getRenderer()->setSize( gme::Vector2(16,16) );
    getTransform()->setScale(gme::Vector2(3,3));
    framecount = 0;
}

void smallExplosion::update() {
    if(reloj.currentTime().asSeconds() > 0.02){
        framecount++;
        if(framecount < 4) getRenderer()->setFrame(gme::Vector2(framecount));
        else destroyGameObject(gameObject());
        reloj.restart();
    }
}


smallExplosion::~smallExplosion() {
}

