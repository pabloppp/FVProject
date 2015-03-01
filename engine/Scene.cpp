#include <iostream>
#include "Scene.hpp"
#include "Game.hpp"
#include "gameobjects/Camera.hpp"

#include <math.h>

using namespace gme;

Scene::Scene(std::string n){
    name = n;
    Game::addScene(this);
    Game::mainCamera = new Camera("mainCamera");
    updateClock.restart();
}

Scene::Scene(const Scene& orig) {
}

Scene::~Scene() {   
    while(!gameObjects.empty()) delete gameObjects.back(), gameObjects.pop_back();
    std::cout << "Destroying scene" << std::endl;
}

void Scene::addGameObject(GameObject *g) {
    /*
    if(gameObjects.empty()) gameObjects.push_back(g);
    else{
        for(int i=0;i<gameObjects.size();i++){
            if(gameObjects.at(i)->getTransform()->getZIndex() > g->getTransform()->getZIndex()){
                gameObjects.insert(gameObjects.begin()+i, g);
                return;
            }
        }
        gameObjects.push_back(g);
    }
    */
    gameObjects.push_back(g);
    //gameObjects.back()->setup();
}

void Scene::destroyGameObject(GameObject* g){
    for(int i=0;i<gameObjects.size();i++){
        if(gameObjects.at(i) == g){
            gameObjects.erase(gameObjects.begin()+i);
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
    
    Vector2 mainCenter( ((Camera*)Game::mainCamera)->getPosition().x, ((Camera*)Game::mainCamera)->getPosition().y );
    Vector2 mainSize = ((Camera*)Game::mainCamera)->getSize();
    
    mainView.setCenter(mainCenter.x+windowSize.x/2, mainCenter.y+windowSize.y/2);
    mainView.setSize(640, 480);
    //std::cout << mainSize.x << " WOWOWOWOW" << std::endl;
    mainView.setSize(mainSize.x*windowSize.x, mainSize.y*windowSize.y);
        
    Game::getWindow()->setView(mainView);
     
            
    float updateTime = 1.0/30.0;
    float now = updateClock.currentTime().asSeconds();
    float frameTime = now - lastTime;
    
    while(frameTime > updateTime){   
        
        Game::deltaTime = updateTime;
        for(int i = gameObjects.size()-1; i >= 0; i--){  
            if(gameObjects.at(i)->isActive()) gameObjects.at(i)->fixedUpdate();
            
            if(gameObjects.at(i)->getCollider() != NULL){
                    for(int j = 0; j < i; j++){
                        if(gameObjects.at(j) != NULL && gameObjects.at(j)->getCollider() != NULL){
                            gameObjects.at(i)->getCollider()->checkCollision(gameObjects.at(j)->getCollider());
                        }
                    }
            }
            
            if(gameObjects.at(i)->isActive()) gameObjects.at(i)->update();
        }
        frameTime -= updateTime;
   
    }
    
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
