/* 
 * File:   sbBehavior.cpp
 * Author: apple
 * 
 * Created on 21 de abril de 2015, 10:41
 */

#include "sbBehavior.hpp"

void sbBehavior::setup() {
    winSize = gme::Game::getWindow()->getSize();
}

void sbBehavior::update() {
    float posX = getTransform()->getPosition().x;
    float posY = getTransform()->getPosition().y;
    
    if((posX < 0 || posX > winSize.x) || (posY < 0 || posY > winSize.y)){
        destroyGameObject(gameObject());
    }
}

sbBehavior::~sbBehavior() {
}

