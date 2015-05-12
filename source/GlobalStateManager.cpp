
#include "GlobalStateManager.hpp"
#include "tilerJsonLoadScene.hpp"
#include "transitionScene.hpp"
#include "PlayerMovement.hpp"
#include "moveToTop.hpp"
#include "weapon.hpp"
#include "pistolaBehavior.hpp"
#include "player.hpp"
#include "metralletaBehavior.hpp"
#include "escopetaBehavior.hpp"
#include "lnzllamasBehavior.hpp"

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
        lastScore += gameClock.currentTime().asSeconds();
        apretar.restart();
    }
    if(!paused && gme::Keyboard::isKeyPressed(menuKey) && apretar.currentTime().asSeconds()>0.2){
        if(!canpause) return; 
        pause();
        sendMessage("openMenu", 0); 
        apretar.restart();
    }
    if(!player2_exists && !paused && gme::Keyboard::isKeyPressed(gme::Keyboard::Period) && apretar.currentTime().asSeconds()>0.2){
        if(!canpause) return; 
        player2_exists = true;
        weapon *arma2 = new weapon("weapon");
        arma2->addComponent(new pistolaBehavior()); 

        player *p2 = new player("p2");
        p2->overrideKeys = true;
        p2->leftKey = gme::Keyboard::A;
        p2->rightKey = gme::Keyboard::D;
        p2->upKey = gme::Keyboard::W;
        p2->downKey = gme::Keyboard::S;
        p2->jumpKey = gme::Keyboard::F;
        p2->weaponKey = gme::Keyboard::G;
        p2->actionKey = gme::Keyboard::H;

        p2->getTransform()->setPosition(gme::Vector2(16*3*2, 576-16*9));
        p2->customize([](gme::GameObject* obj) {
            obj->getRenderer()->setTexture("player1Texture");
        });

        p2->addChild(arma2);
        arma2->getTransform()->setPosition(gme::Vector2(0,0));
        
        metralletaBehavior *mb = new metralletaBehavior();
        mb->setActive(false);
        arma2->addComponent(mb);
        escopetaBehavior *eb =  new escopetaBehavior();
        eb->setActive(false);
        arma2->addComponent(eb);
        lnzllamasBehavior *lb =  new lnzllamasBehavior();
        lb->setActive(false);
        arma2->addComponent(lb);
        
        instantiate(p2);
        instantiate(arma2);
        apretar.restart();
    }
    if( gameType == 1 && gameClock.currentTime().asSeconds()+lastScore >= winCondition && !gameOver){
        if(!paused && !levelSuccess){
            gameObject()->sendMessage("showLevelSuccess", 0);
            levelSuccess = true;
            canpause = false;
            paused = true;
        }
        if(levelSuccess && gme::Keyboard::isKeyPressed(gme::Keyboard::Return)){
            //Se abre una nueva escena 
            if(nextScene.length() != 0) gme::Game::setCurrentScene(nextScene);
            
        }
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
                            || ol->at(i)->hasTag("colectable")
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
                gameClock.restart();
                lastScore = 0;
            }
        }
    }
}

void GlobalStateManager::onMessage(std::string m, float v) {
    if(!paused && m.compare("pause")==0) {
        if(canpause){
            pause();
            lastScore = gameClock.currentTime().asSeconds();
            std::cout << "Queda: " << lastScore << std::endl;
        }
        
    }
    else if(paused && m.compare("resume")==0){
        if(canpause){
            resume();
            gameClock.restart();
        } 
    }
    else if(m.compare("gameover")==0){
        canpause = false;
        gameOver = true;
        pause();
        lastScore += gameClock.currentTime().asSeconds();
    }
}

GlobalStateManager::~GlobalStateManager() {

}
