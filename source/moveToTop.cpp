#include "moveToTop.hpp"

void moveToTop::setup() {
    doClock.restart();
    move();
}

void moveToTop::update() {
   
    if(automove) move();
    
}

void moveToTop::move() {
    std::vector<gme::GameObject*> *objects = gme::Game::getCurrentScene()->getGameObjects();
   
    int p = orderpostion;
    if(p < 0) p = objects->size()+p;
    
    if(objects->at(p) != gameObject()){
        for(int i=0;i<objects->size();i++){
            if(objects->at(i) == gameObject()){
                gme::GameObject *current = objects->at(i);
                objects->erase(objects->begin()+i);
                objects->insert(objects->begin()+p, current);
                return;
            }
        }
    }
}


void moveToTop::setOrder(int o) {
    orderpostion = o;
}




