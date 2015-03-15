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
    Game::mainCamera = new Camera("mainCamera");
    updateClock.restart();
    gameObjects.reserve(99999);
    Vector2 wsize = Game::getWindow()->getSize();
    
    b2Vec2 gravity(0.0f, 9.81f);
    boxWorld = new b2World(gravity);
    addGameObject(Game::mainCamera);
}



Scene::Scene(const Scene& orig) {
}

Scene::~Scene() {   
    while(!gameObjects.empty()) delete gameObjects.back(), gameObjects.pop_back();
    std::cout << "Destroying scene" << std::endl;
}

void Scene::addGameObject(GameObject *g) {
    gameObjects.push_back(g);
}

void Scene::destroyGameObject(GameObject* g){
    for(int i=0;i<gameObjects.size();i++){
        if(gameObjects.at(i) == g){
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
            if(gameObjects.at(i)->isActive()){
                gameObjects.at(i)->earlyUpdate();
            }
        }
        
        boxWorld->Step(updateTime, 8, 3);
        
        //update
        for(int i = gameObjects.size()-1; i >= 0; i--){
            if(gameObjects.at(i)->isActive()) gameObjects.at(i)->update();
        }
        
        
        frameTime -= updateTime;
   
    }
    
    //Fixed update

    for(int i = gameObjects.size()-1; i >= 0; i--){
        if(gameObjects.at(i)->isActive()){
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
    for(int i = gameObjects.size()-1; i >= 0; i--){
         if(gameObjects.at(i)->isActive()) gameObjects.at(i)->getRenderer()->update();
    }

    Game::getWindow()->setView(Game::getWindow()->getDefaultView());
    for(int i = gameObjects.size()-1; i >= 0; i--){     
        if(gameObjects.at(i)->isActive()) gameObjects.at(i)->drawGui();
    }

    Game::getWindow()->display();
    
    //std::cout << "fixed fps: " << 1.0/Game::deltaTime.asSeconds() << std::endl;
    //std::cout << "fps: " << 1.0/Game::unfixedDeltaTime.asSeconds() << std::endl;

}

void Scene::superSetup(){
    setup();
    for(int i = gameObjects.size()-1; i >= 0; i--) gameObjects.at(i)->setup();
    for(int i = gameObjects.size()-1; i >= 0; i--) gameObjects.at(i)->componentSetup();   
}

std::string Scene::getName(){
    return name;
}
