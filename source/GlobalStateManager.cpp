
#include "GlobalStateManager.hpp"

void GlobalStateManager::pause(){
    std::cout << "Pausando juego desde el State Manager" << std::endl;
    paused = true;
}

void GlobalStateManager::resume(){
    std::cout << "Volviendo al juego desde el State Manager" << std::endl;
    paused = false;
}

void GlobalStateManager::setup(){

}

void GlobalStateManager::update(){
    
    if(!paused && gme::Keyboard::isKeyPressed(pauseKey) && apretar.currentTime().asSeconds()>0.2){
        pause();
        sendMessage("openPause", 0); 
        apretar.restart();
    }
    if(!paused && gme::Keyboard::isKeyPressed(menuKey) && apretar.currentTime().asSeconds()>0.2){
        pause();
        sendMessage("openMenu", 0); 
        apretar.restart();
    } 
}

void GlobalStateManager::onMessage(std::string m, float v) {
    if(!paused && m.compare("pause")==0) {
        pause();
    }
    else if(paused && m.compare("resume")==0){
        resume();
    }
}

GlobalStateManager::~GlobalStateManager() {

}
