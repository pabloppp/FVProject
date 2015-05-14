#include <iostream>

#include "Game.hpp"
#include "GUI.hpp"

using namespace gme;
 
Game::Game(Vector2 windowSize, std::string name){
    window = new Window(windowSize.x, windowSize.y, name);
    window->setVerticalSyncEnabled(true);
    window->setFrameLimit(60);
    currentScene = NULL;
    deltaTime.Zero();
    GUI::loadFont("engine/resources/mainfont.ttf");
}

Game::Game(const Game& orig) {
 
}

Game::~Game() {
    delete gme::Game::mainCamera;
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

Scene* Game::removeScene(std::string n) {
    for(int i=0;i<scenes.size();i++){
        if(scenes.at(i)->getName().compare(n) == 0){
            Scene *es = scenes.at(i); 
            scenes.erase(scenes.begin()+i); 
            scenesToDelete.push_back(es);
            return es;
        }
    }
}

Scene* Game::removeScene(Scene *s) {
    for(int i=0;i<scenes.size();i++){
        if(scenes.at(i) == s){
            scenes.erase(scenes.begin()+i); 
            scenesToDelete.push_back(s);
            return s;
        }
    }
}


Scene* Game::getScene(std::string s) {
    for(int i=0;i<scenes.size();i++){
        if(scenes.at(i)->getName().compare(s) == 0){
            //std::cout << s << ": " << scenes.at(i)->getName() << std::endl;
            return scenes.at(i);
        }
    }
    return NULL;
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

        unfixedDeltaTime = deltaClock.restart();
        //deltaTime = unfixedDeltaTime;
                
        sf::Event event;
        while (window->pollEvent(event))
        {
            if(event.type == sf::Event::KeyPressed){
                keysPressed.push_back(event.key.code);
                
            } 
            else if(event.type == sf::Event::KeyReleased){
                int n;
                for(int i=keysPressed.size()-1;i>=0;i--){
                    if(keysPressed.at(i) == event.key.code){
                        keysPressed.erase(keysPressed.begin()+i);
                    };
                }   
            }
                
            if (event.type == sf::Event::Closed) window->close();
        }
        
        //window->clear();
        
        if(currentScene && currentScene != NULL && currentScene != nullptr) currentScene->update();  
        
        while(!scenesToDelete.empty()) delete scenesToDelete.back(), scenesToDelete.pop_back();
        
        
        //window->display();
    }
    delete window;
}

bool Game::isKeyPressed(int k) {
    for(int i=keysPressed.size()-1;i>=0;i--){
        if(keysPressed.at(i) == k){
            return true;
        };
    }
    return false;
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

void Game::newSound(const std::string& path, const std::string& name){
    Sound newSound;
    if(!newSound.loadFromFile(path)){
        std::cout << "error loading sound from: " << path << std::endl;
        return;
    }
    newSound.setName(name);
    sounds.push_back(newSound);
}

Sound *Game::getSound(const std::string& name){
    for(int i=0;i<sounds.size();i++){
        if(sounds.at(i).getName().compare(name) == 0) return &sounds.at(i);
    }
    return NULL;
}



void Game::newMusic(const std::string& path, const std::string& name){
    Music *newMusic = new Music();
    if(!newMusic->openFromFile(path)){
        std::cout << "error loading music from: " << path << std::endl;
        return;
    }
    newMusic->setName(name);
    musics.push_back(newMusic);
}

Music *Game::getMusic(const std::string& name){
    for(int i=0;i<musics.size();i++){
        if(musics.at(i)->getName().compare(name) == 0) return musics.at(i);
    }
    return NULL;
}

int Game::addTag(const std::string& s) {
    if(tagmap.find(s) != tagmap.end()) return tagmap[s];
    if(tagCount >= 15) return -1;
    else{
        tagCount++;
        tagmap[s] = tagCount;       
        return tagmap[s];
    }
}

std::unordered_map<std::string, unsigned int>* Game::getTags() {
    return &tagmap;
}



Time Game::deltaTime;

Time Game::unfixedDeltaTime;
 
Window *Game::window = NULL;

Scene *Game::currentScene = NULL;

GameObject *Game::mainCamera = NULL;

std::vector<Scene*> Game::scenes;
std::vector<Scene*> Game::scenesToDelete;

std::vector<Texture> Game::textures;

std::vector<Sound> Game::sounds;
std::vector<Music*> Game::musics;

bool Game::debugColliders = false;

Clock Game::updateClock;

float Game::ticPercent = 0;

std::unordered_map<std::string, unsigned int> Game::tagmap;

char Game::tagCount = 0;

std::vector<int> Game::keysPressed;
