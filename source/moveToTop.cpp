#include "moveToTop.hpp"

void moveToTop::setup() {
    doClock.restart();
}

void moveToTop::update() {
    
    if(gameObject()->getName().compare("weapon")==0 && doClock.currentTime().asSeconds() > 0.3) return;
    if(gameObject()->hasTag("player") && doClock.currentTime().asSeconds() > 0.2) return;
            
    std::vector<gme::GameObject*> *objects = gme::Game::getCurrentScene()->getGameObjects();
    
    for(int i=0;i<objects->size();i++){
        if(objects->at(i) == gameObject() 
                && (gameObject()->getName().compare("weapon")==0 || gameObject()->hasTag("player"))){
            objects->erase(objects->begin()+i);
            objects->push_back(gameObject());
            break;
        }
    }
}


