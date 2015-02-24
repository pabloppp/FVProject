#include <iostream>

#include "Game.hpp"

using namespace gme;
 
Game::Game(sf::Vector2f windowSize, std::string name){
    window = new Window(windowSize.x, windowSize.y, name);
    window->setVerticalSyncEnabled(true);
    currentScene = NULL;
    deltaTime.Zero();
}

Game::Game(const Game& orig) {
 
}

Game::~Game() {
    while(!scenes.empty()) delete scenes.back(), scenes.pop_back();
    std::cout << "Destroying game instance" << std::endl;
    //delete currentScene;
}

void Game::setCurrentScene(Scene *s){
    currentScene = s;
    currentScene->superSetup();
}

void Game::setCurrentScene(std::string n){
    for(int i=0;i<scenes.size();i++){
        if(scenes.at(i)->getName().compare(n) == 0){
            setCurrentScene(scenes.at(i));
            return;
        }
    }
}

Scene *Game::getCurrentScene(){
    return currentScene;
}

Window *Game::getWindow(){
    return window;
}

void Game::addScene(Scene *s){
    scenes.push_back(s);
}

void Game::run(){
    
    setup();
    while(window->isOpen()){

        deltaTime = deltaClock.restart();
        
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window->close();
        }
        
        window->clear();
        
        if(currentScene != NULL) currentScene->update();  
        
        
        window->display();
    }
    delete window;
}

void Game::newTexture(const std::string &path, const std::string &name){
    Texture newTex;
    if(!newTex.loadFromFile(path)){
        std::cout << "error loading image from: " << path << std::endl;
        return;
    }
    newTex.setName(name);
    textures.push_back(newTex);
}

Texture *Game::getTexture(const std::string &name){
    for(int i=0;i<textures.size();i++){
        if(textures.at(i).getName().compare(name) == 0) return &textures.at(i);
    }
    return NULL;
}

Time Game::deltaTime;
 
Window *Game::window = NULL;

Scene *Game::currentScene = NULL;

GameObject *Game::mainCamera = NULL;

std::vector<Scene*> Game::scenes;

std::vector<Texture> Game::textures;

bool Game::debugColliders = false;

