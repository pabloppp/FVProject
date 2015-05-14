#include <iostream>
#include "Scene.hpp"
#include "Game.hpp"
#include "gameobjects/Camera.hpp"

#include <math.h>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace gme;

Scene::Scene(std::string n){
    name = n;
    Game::addScene(this);
    //if(Game::mainCamera != NULL) delete Game::mainCamera; 
    Game::mainCamera = new Camera("mainCamera");
    updateClock.restart();
    gameObjects.reserve(99999);
    Vector2 wsize = Game::getWindow()->getSize();
    boxWorld = NULL;
    addGameObject(Game::mainCamera);
    lastTime = 0;
}



Scene::Scene(const Scene& orig) {
}

Scene::~Scene() { 
    std::cout << this->getName() << std::endl;
    for(int i=gameObjects.size()-1; i>=0;i--){
        if(gameObjects.at(i) != Game::mainCamera && gameObjects.at(i)->getName().compare("mainCamera") != 0){
            try{
                if(gameObjects.at(i) && gameObjects.at(i) != NULL && gameObjects.at(i) != nullptr){
                    //std::cout << "objetos: " << gameObjects.size() << std::endl;
                    if(gameObjects.size() == 3) std::cout << gameObjects.at(i)->getName() << std::endl;
                    delete gameObjects.at(i);
                }
            }catch(std::exception& e){
                std::cout << "erroratrapa" << std::endl;
            } 
            //std::cout << "objetos: " << gameObjects.at(i) << std::endl;
            gameObjects.at(i) = nullptr;
            gameObjects.erase(gameObjects.begin()+i);
        }
    }
    std::cout << "Destroying scene" << std::endl;
}

void Scene::addGameObject(GameObject *g) {
    gameObjects.push_back(g);
}

void Scene::destroyGameObject(GameObject* g){
    for(int i=gameObjects.size()-1;i>=0;i--){
        if(i < gameObjects.size() && gameObjects.at(i) == g){
            
            if(gameObjects.at(i)->getChildren().size() > 0){
                while(gameObjects.at(i)->getChildren().size() > 0){
                    GameObject *child = gameObjects.at(i)->getChildren().at(0);
                    gameObjects.at(i)->removeChild(child);
                    destroyGameObject(child);
                }
            }
            
            gameObjects.at(i) = gameObjects.back();
            gameObjects.pop_back();
            delete g;
            return;
        }
    }    
}

void Scene::instantiate(GameObject* g){
    g->setup();
    g->componentSetup();
}

std::vector<GameObject*> *Scene::getGameObjects(){
    return &gameObjects;
}

void Scene::update(){
    //UPDATE SCRIPTS   
    Vector2 windowSize = Game::getWindow()->getSize();
    Vector2 originalSize = Game::getWindow()->getOriginalSize();
    float stretchX = 1.f*originalSize.x/windowSize.x;
    float stretchY = 1.f*originalSize.y/windowSize.y;
    
    Vector2 mainCenter( ((Camera*)Game::mainCamera)->getPosition().x, ((Camera*)Game::mainCamera)->getPosition().y );
    Vector2 mainSize = ((Camera*)Game::mainCamera)->getSize();
    
    
    mainView.setSize(stretchX*mainSize.x*windowSize.x, stretchY*mainSize.y*windowSize.y);
    mainView.setCenter(mainCenter.x/stretchX+stretchX*windowSize.x/2.0, mainCenter.y/stretchY+stretchY*windowSize.y/2);

        
    Game::getWindow()->setView(mainView);
     
            
    float updateTime = 1.0/30.0;
    float now = updateClock.currentTime().asSeconds();
    float frameTime = now - lastTime;
        
    while(frameTime > updateTime){
                
        Game::deltaTime = updateTime;
        
        for(int i = gameObjects.size()-1; i >= 0; i--){
            if(i < gameObjects.size() && gameObjects.at(i)->isActive()){
                gameObjects.at(i)->earlyUpdate();
            }
        }
        
        boxWorld->Step(updateTime, 8, 3);
        
        //update
        for(int i = gameObjects.size()-1; i >= 0; i--){
            if(i < gameObjects.size() && gameObjects.at(i)->isActive()) gameObjects.at(i)->update();
        }
        
        
        frameTime -= updateTime;
   
    }
    
    //Fixed update

    for(int i = gameObjects.size()-1; i >= 0; i--){
        if(i < gameObjects.size() && gameObjects.at(i)->isActive()){
            gameObjects.at(i)->fixedUpdate();
        }
    }
    
    mainCenter = Vector2( ((Camera*)Game::mainCamera)->getPosition().x, ((Camera*)Game::mainCamera)->getPosition().y );
    mainSize = ((Camera*)Game::mainCamera)->getSize();
       
    mainView.setSize(stretchX*mainSize.x*windowSize.x, stretchY*mainSize.y*windowSize.y);
    mainView.setCenter(mainCenter.x/stretchX+stretchX*windowSize.x/2.0, mainCenter.y/stretchY+stretchY*windowSize.y/2);
        
    Game::getWindow()->setView(mainView);
    
    
    lastTime = now - frameTime;
        
    Game::ticPercent = fmin(1.f, updateClock.currentTime().asSeconds()/frameTime);     
    //RENDER 
    Game::getWindow()->clear();
    for(int i = 0; i < gameObjects.size(); i++){
         if(i < gameObjects.size() && gameObjects.at(i)->isActive()) gameObjects.at(i)->getRenderer()->update();
    }

    Game::getWindow()->setView(Game::getWindow()->getDefaultView());
    for(int i = 0; i < gameObjects.size(); i++){     
        if(i < gameObjects.size() && gameObjects.at(i)->isActive()) gameObjects.at(i)->drawGui();
    }

    Game::getWindow()->display();
    
    //std::cout << "fixed fps: " << 1.0/Game::deltaTime.asSeconds() << std::endl;
    //std::cout << "fps: " << 1.0/Game::unfixedDeltaTime.asSeconds() << std::endl;

}

void Scene::superSetup(){
    b2Vec2 gravity(0.0f, 9.81f);
    boxWorld = new b2World(gravity);
    setup();
    for(int i = gameObjects.size()-1; i >= 0; i--) gameObjects.at(i)->setup();
    for(int i = gameObjects.size()-1; i >= 0; i--) gameObjects.at(i)->componentSetup();   
}

std::string Scene::getName(){
    return name;
}
