#include "moveClouds.hpp"

void moveClouds::setup() {
    initX = getTransform()->getPosition().x;
    initY = getTransform()->getPosition().y;
}

void moveClouds::update() {
    gme::Vector2 oldp;    
    oldp.x = speed*gme::Game::deltaTime.asSeconds();
    getTransform()->translate(oldp);
    if(getTransform()->getPosition().x > 1024*1.5){
        getTransform()->translate(gme::Vector2(-1024*2, 0));
    }
    
}


moveClouds::~moveClouds() {
}

