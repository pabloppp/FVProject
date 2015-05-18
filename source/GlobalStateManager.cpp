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
#include "oleada2.hpp"
#include "mainGame.hpp"
#include "oleada3.hpp"
#include "oleada4.hpp"
#include "oleada5.hpp"
#include "oleada6.hpp"
#include "oleada7.hpp"
#include "oleada8.hpp"
#include "oleada9.hpp"
#include "oleada10.hpp"
#include "MenuManager.hpp"

void GlobalStateManager::pause(){
    if(!canpause) return; 
    std::cout << "Pausando juego desde el State Manager" << std::endl;
    paused = true;
    anim.pause();
}

void GlobalStateManager::resume(){
    if(!canpause) return; 
    std::cout << "Volviendo al juego desde el State Manager" << std::endl;
    paused = false;
    anim.resume();
}

void GlobalStateManager::setup(){    
    ready_player= new gme::SoundPlayer();
    ready_player->setSound("ready_sound");   
    if(mainGame::coop) spawnP2();
    pause();
}

bool GlobalStateManager::isPaused() {
    return paused;
}


void GlobalStateManager::update(){
    
    anim.animate();
    // El jugador pausa el juego
    if(paused && !startready){
        sendMessage("readygo", 0); 
        startready = true;        
    }
    if(!paused && (gme::Keyboard::isKeyPressed(pauseKey) || (gme::Keyboard::isKeyPressed(escKey))) 
            && apretar.currentTime().asSeconds()>0.2){
        if(!canpause) return; 
        pause();
        sendMessage("openPause", 0); 
        lastScore += gameClock.currentTime().asSeconds();
        apretar.restart();
    }
    
    // Tipo de juego por tiempo ganado
    if(gameType == 1 && gameClock.currentTime().asSeconds()+lastScore >= winCondition && !gameOver){
        if(!paused && !levelSuccess){
            mainGame::levelspassed += 1;
            mainGame::saveProfile();
            
            maxpoints = 0;
            int level = 0;
            if(mainGame::getCurrentScene()->getName().compare("oleada1") == 0) level = 0;
            else if(mainGame::getCurrentScene()->getName().compare("oleada2") == 0) level = 1;
            else if(mainGame::getCurrentScene()->getName().compare("oleada3") == 0) level = 2;
            else if(mainGame::getCurrentScene()->getName().compare("oleada4") == 0) level = 3;
            else if(mainGame::getCurrentScene()->getName().compare("oleada5") == 0) level = 4;
            else if(mainGame::getCurrentScene()->getName().compare("oleada6") == 0) level = 5;
            else if(mainGame::getCurrentScene()->getName().compare("oleada7") == 0) level = 6;
            else if(mainGame::getCurrentScene()->getName().compare("oleada8") == 0) level = 7;
            else if(mainGame::getCurrentScene()->getName().compare("oleada9") == 0) level = 8;
            else if(mainGame::getCurrentScene()->getName().compare("oleada10") == 0) level = 9;
            
                
            std::vector<gme::GameObject*> players = gme::GameObject::findWithTag("player");
            for(int i=0;i<players.size();i++){
                
                int points = ((PlayerMovement*)(players.at(i)->getComponent<PlayerMovement*>()))->points;
                if(points > maxpoints) maxpoints = points; 
                
                if(players.at(i)->getName().compare("p1") == 0) pointsp1 = points;
                else if(players.at(i)->getName().compare("p2") == 0) pointsp2 = points;
                
            }
            if(maxpoints > mainGame::maxpoints[level]){
                mainGame::maxpoints[level] = maxpoints;
                mainGame::savePoints();
            }
            
            maxpoints = mainGame::maxpoints[level];
            
            gameObject()->sendMessage("showLevelSuccess", 0);
            levelSuccess = true;
            canpause = false;
            paused = true;
        }
        if(levelSuccess && gme::Keyboard::isKeyPressed(gme::Keyboard::Return)){
            //Se abre una nueva escena 
            //mainGame::sound = true;
            if(nextScene.length() != 0){
                gme::Scene *olds = gme::Game::removeScene(gme::Game::getCurrentScene());
                gme::Scene *olds2 = gme::Game::removeScene(nextScene);
                if(nextScene.compare("oleada2") == 0){
                    gme::Scene *news = new oleada2("oleada2");
                }
                if(nextScene.compare("oleada3") == 0){
                    gme::Scene *news = new oleada3("oleada3");
                }
                if(nextScene.compare("oleada4") == 0){
                    gme::Scene *news = new oleada4("oleada4");
                }
                if(nextScene.compare("oleada5") == 0){
                    gme::Scene *news = new oleada5("oleada5");
                }
                if(nextScene.compare("oleada6") == 0){
                    gme::Scene *news = new oleada6("oleada6");
                }
                if(nextScene.compare("oleada7") == 0){
                    gme::Scene *news = new oleada7("oleada7");
                }
                if(nextScene.compare("oleada8") == 0){
                    gme::Scene *news = new oleada8("oleada8");
                }
                if(nextScene.compare("oleada9") == 0){
                    gme::Scene *news = new oleada9("oleada9");
                }
                if(nextScene.compare("oleada10") == 0){
                    gme::Scene *news = new oleada10("oleada10");
                }
                gme::Game::setCurrentScene(nextScene);
            }
            
        }
    }
    //Si perdemos...
    if(gameOver){
        //mainGame::sound = false;
        isGameOver();
        
        
    }
    
    if(goToMenu) gme::Game::setCurrentScene("mainmenu");
}

void GlobalStateManager::spawnP2() {
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
}


void GlobalStateManager::isGameOver() {
    if(gme::Keyboard::isKeyPressed(gme::Keyboard::Return)){
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
                
                std::vector<gme::GameObject*> children = players.at(i)->getChildren();
                
                gme::Component *pb = children.at(0)->getComponent<pistolaBehavior*>();
                gme::Component *mb = children.at(0)->getComponent<metralletaBehavior*>();
                gme::Component *eb = children.at(0)->getComponent<escopetaBehavior*>();
                gme::Component *lb = children.at(0)->getComponent<lnzllamasBehavior*>();
                
                if(pb != NULL) pb->setActive(true);
                if(mb != NULL) mb->setActive(false);
                if(eb != NULL) eb->setActive(false);
                if(lb != NULL) lb->setActive(false);

                if(i==0) players.at(i)->getTransform()->setPosition(gme::Vector2(16*3, 576-16*9));
                else players.at(i)->getTransform()->setPosition(gme::Vector2(16*3*2, 576-16*9));

                players.at(i)->getComponent<PlayerMovement*>()->setup();
                ((gme::GameObject*)(players.at(i)))->getComponent<moveToTop*>()->setup();
                players.at(i)->sendMessage("reset",0);
                ((gme::GameObject*)(players.at(i)->getChildren()[0]))->getComponent<moveToTop*>()->setup();
                
            }

            gameObject()->sendMessage("reset", 0);
            
            anim.restart();

            gameOver = false;
            canpause = true;
            gameClock.restart();
            lastScore = 0;
        }
    }
}




void GlobalStateManager::onMessage(std::string m, float v) {
    if(!paused && m.compare("pause")==0) {
        if(canpause){
            pause();
            lastScore = gameClock.currentTime().asSeconds();
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
        mainGame::deaths += 1;
        mainGame::saveProfile();
    }
}

GlobalStateManager::~GlobalStateManager() {

}

int GlobalStateManager::pointsp1 = 0;
int GlobalStateManager::pointsp2 = 0;
int GlobalStateManager::maxpoints = 0;
