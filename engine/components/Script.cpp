#include "Script.hpp"

using namespace gme;

#include "../GameObject.hpp"
#include "../Game.hpp"

Transform *Script::getTransform(){
    return gameObject()->getTransform();
}

Renderer *Script::getRenderer(){
    return gameObject()->getRenderer();
}

Collider *Script::getCollider(){
    return gameObject()->getCollider();    
}

RigidBody *Script::getRigidBody(){
    return gameObject()->getRigidBody();
}

void Script::destroyGameObject(GameObject* g){
    if(Game::getCurrentScene() != NULL){
        std::vector<GameObject*> children = g->getChildren();
        for(int i=0;i<children.size();i++){
            g->removeChild(children.at(i));
            Game::getCurrentScene()->destroyGameObject(children.at(i));
        }
        if(g->getParent() != NULL) g->getParent()->removeChild(g);
        Game::getCurrentScene()->destroyGameObject(g);
    }
}

void Script::instantiate(GameObject* g){
    if(Game::getCurrentScene() != NULL){
        Game::getCurrentScene()->instantiate(g);
    }
}

void Script::broadcastMessage(std::string s, float f) {
    if(gameObject() != NULL) gameObject()->broadcastMessage(s,f);
}

void Script::sendMessage(std::string s, float f) {
    if(gameObject() != NULL) gameObject()->sendMessage(s,f);
}

void Script::sendMessageUpward(std::string s, float f) {
    if(gameObject() != NULL) gameObject()->sendMessageUpward(s,f);
}


