/* 
 * File:   jaulaScript.cpp
 * Author: pablopernias
 * 
 * Created on 20 de mayo de 2015, 12:21
 */

#include "jaulaScript.hpp"
#include "moveToTop.hpp"

void jaulaScript::setup() {
    
}

void jaulaScript::update() {
    if(moving){
        if(reloj.currentTime().asSeconds() > 0.1){
            frame++;
            if(frame > 27){
                moving = false;
                getRenderer()->setFrame(gme::Vector2(0, 0));
                frame = 0;
            }
            if(frame == 1 || frame == 7 || frame == 17 || frame == 19 || frame == 25) getRenderer()->setFrame(gme::Vector2(1,0));
            if(frame == 2 || frame == 6 || frame == 18) getRenderer()->setFrame(gme::Vector2(2,0));
            if(frame == 3 || frame == 5) getRenderer()->setFrame(gme::Vector2(3,0));
            if(frame == 4) getRenderer()->setFrame(gme::Vector2(4,0));
            if(frame == 8 || frame == 16 || frame == 20 || frame == 24 || frame == 26) getRenderer()->setFrame(gme::Vector2(0,0));
            if(frame == 9 || frame == 15 || frame == 21 || frame == 23 || frame == 27) getRenderer()->setFrame(gme::Vector2(8,0));
            if(frame == 10 || frame == 14 || frame == 22 ) getRenderer()->setFrame(gme::Vector2(7,0));
            if(frame == 11 || frame == 13) getRenderer()->setFrame(gme::Vector2(6,0));
            if(frame == 12) getRenderer()->setFrame(gme::Vector2(5,0));
            reloj.restart();
        } 
    }
}

void jaulaScript::onCollision(gme::Collider* c) {
    if(c->gameObject()->hasTag("player") && !moving){
        moving = true;
        reloj.restart();
    }
}

jaulaScript::~jaulaScript() {
    
}


