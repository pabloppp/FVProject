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
        Game::getCurrentScene()->destroyGameObject(g);
    }
}

void Script::instantiate(GameObject* g){
    if(Game::getCurrentScene() != NULL){
        Game::getCurrentScene()->instantiate(g);
    }
}

