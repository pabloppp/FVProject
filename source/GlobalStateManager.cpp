
#include "GlobalStateManager.hpp"
#include "tilerJsonLoadScene.hpp"
#include "transitionScene.hpp"
#include "PlayerMovement.hpp"
#include "moveToTop.hpp"

void GlobalStateManager::pause(){
    if(!canpause) return; 
    std::cout << "Pausando juego desde el State Manager" << std::endl;
    paused = true;
}

void GlobalStateManager::resume(){
    if(!canpause) return; 
    std::cout << "Volviendo al juego desde el State Manager" << std::endl;
    paused = false;
}

void GlobalStateManager::setup(){

}

bool GlobalStateManager::isPaused() {
    return paused;
}


void GlobalStateManager::update(){
    
    if(!paused && gme::Keyboard::isKeyPressed(pauseKey) && apretar.currentTime().asSeconds()>0.2){
        if(!canpause) return; 
        pause();
        sendMessage("openPause", 0); 
        apretar.restart();
    }
    if(!paused && gme::Keyboard::isKeyPressed(menuKey) && apretar.currentTime().asSeconds()>0.2){
        if(!canpause) return; 
        pause();
        sendMessage("openMenu", 0); 
        apretar.restart();
    }
    
    if(gameOver){
        if(gme::Keyboard::isKeyPressed(gme::Keyboard::Return)){
            gme::Scene *newScene;
            if(true){
                std::vector<gme::GameObject*> *ol = gme::Game::getCurrentScene()->getGameObjects();
                for(int i=ol->size()-1; i>=0; i--){
                    if(ol->at(i)->hasTag("enemy")
                            || ol->at(i)->getName().compare("tile")==0
                            || ol->at(i)->getName().compare("sceneLoader")==0
                            ){
                        
                        delete ol->at(i);
                        ol->at(i) = ol->back();
                        ol->pop_back();
                        
                    }
                }
                for(int i=ol->size()-1; i>=0; i--){
                    if(ol->at(i)->hasTag("floor")){
                        delete ol->at(i);
                        ol->at(i) = ol->back();
                        ol->pop_back();
                    }
                }
                
                gme::Game::getCurrentScene()->setup();
                instantiate(gme::GameObject::find("sceneLoader")[0]);
                
                std::vector<gme::GameObject*> players =  gme::GameObject::findWithTag("player");
                for(int i=0;i<players.size();i++){
                    
                    if(i==0) players.at(i)->getTransform()->setPosition(gme::Vector2(16*3, 576-16*9));
                    else players.at(i)->getTransform()->setPosition(gme::Vector2(16*3*2, 576-16*9));
                    
                    players.at(i)->getComponent<PlayerMovement*>()->setup();
                    ((gme::GameObject*)(players.at(i)))->getComponent<moveToTop*>()->setup();
                    players.at(i)->sendMessage("reset",0);
                    ((gme::GameObject*)(players.at(i)->getChildren()[0]))->getComponent<moveToTop*>()->setup();
                }
                
                gameObject()->sendMessage("reset", 0);
                
                gameOver = false;
                canpause = true;
            }
        }
    }
}

void GlobalStateManager::onMessage(std::string m, float v) {
    if(!paused && m.compare("pause")==0) {
        if(canpause) pause();
    }
    else if(paused && m.compare("resume")==0){
        if(canpause) resume();
    }
    else if(m.compare("gameover")==0){
        canpause = false;
        gameOver = true;
    }
}

GlobalStateManager::~GlobalStateManager() {

}
