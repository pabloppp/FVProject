#include <iostream>
#include <algorithm>

#include "GameObject.hpp"
#include "Scene.hpp"
#include "Game.hpp"

#include "components/Transform.hpp"
#include "components/Renderer.hpp"
#include "components/Collider.hpp"
#include "components/RigidBody.hpp"
#include "components/Script.hpp"
#include "components/SoundPlayer.hpp"

using namespace gme;

GameObject::GameObject(std::string n) {
    name = n;
    active = true;
    parent = NULL;
    transform = new Transform();
    transform->setGameObject(this);
    transform->setScale(Vector2(1,1));
    renderer = new Renderer();
    renderer->setGameObject(this);
    collider = NULL;
    rigidBody = NULL;
    if(Game::getCurrentScene() != NULL) Game::getCurrentScene()->addGameObject(this);
}

GameObject::GameObject(const GameObject& orig) {
    
}

std::string GameObject::getName(){
    return name;
}

GameObject::~GameObject() {
    while(!components.empty())delete components.back(), components.pop_back();
    renderer = NULL;
    delete renderer;
    transform = NULL;
    delete transform;
    if(rigidBody != NULL){
        delete rigidBody;
        rigidBody = NULL;       
    }
    if(collider != NULL){
        delete collider;       
        collider = NULL;       
    }
    //std::cout << "Destroying object " << name << std::endl;
}

void GameObject::update(){
    
    if(rigidBody != NULL) rigidBody->updatep(); 
    for(int i = components.size()-1; i >= 0; i--){
        if(components.at(i)->isActive()) components.at(i)->update();
    }

}

void GameObject::earlyUpdate() {
    if(rigidBody != NULL) rigidBody->update();
    if(collider != NULL) collider->update(); 
    if(transform != NULL) transform->update();
}


void GameObject::fixedUpdate() {    
    for(int i = components.size()-1; i >= 0; i--){
        if(components.at(i)->isActive()) components.at(i)->fixedUpdate();
    }
}

void GameObject::drawGui(){
    for(int i = components.size()-1; i >= 0; i--){
        if(dynamic_cast<Script*>(components.at(i)) && components.at(i)->isActive()) ((Script*)(components.at(i)))->onGui();
    }
}

void GameObject::addTag(std::string t){
    tagmap[t] = t;
}

std::unordered_map<std::string, std::string> *GameObject::getTags(){
    return &tagmap;
}

bool GameObject::hasTag(const std::string& t){
    if(tagmap.find(t) != tagmap.end()) return true;
    return false;
}

std::vector<GameObject*> GameObject::findWithTag(std::string s){
    std::vector<GameObject*> *vect;
    std::vector<GameObject*> result;
    vect = Game::getCurrentScene()->getGameObjects();
    
    for(int i=0;i<vect->size();i++){
        if(vect->at(i)->getTags()->find(s) != vect->at(i)->getTags()->end()) result.push_back(vect->at(i));
    }
    return result;
}

std::vector<GameObject*> GameObject::find(std::string s){
    std::vector<GameObject*> *vect;
    std::vector<GameObject*> result;
    vect = Game::getCurrentScene()->getGameObjects();
    
    for(int i=0;i<vect->size();i++){
        if(vect->at(i)->getName().compare(s) == 0) result.push_back(vect->at(i));
    }
    return result;
}

// TO DO
void GameObject::sendMessage(std::string s, float f){
    //...
}

void GameObject::broadcastMessage(std::string s, float f){
    //...
}
//~~~~

void GameObject::addComponent(Component* c){
    if(dynamic_cast<Transform*>(c)){
        std::cout << "GameObject already owns a transform" << std::endl;
    }
    else if(dynamic_cast<Renderer*>(c)){
        std::cout << "GameObject already owns a renderer" << std::endl;
    }
    else if(dynamic_cast<Collider*>(c)){
        if(getRigidBody() != NULL){
            c->setGameObject(this);
            collider = (Collider*)c;
        }
        else{
            std::cout << "NO COLLIDER WITHOUT RIGIDBODY" << std::endl;
            delete c;
        }
    }
    else if(dynamic_cast<RigidBody*>(c)){
        c->setGameObject(this);
        rigidBody = (RigidBody*)c;
    }
    else{
        c->setGameObject(this);
        components.push_back(c);
        //std::cout << "Unknown component type" << std::endl; 
    }
}

void GameObject::componentSetup(){
    transform->setup();
    renderer->setup();
    if(collider != NULL) collider->setup();
    if(rigidBody != NULL) rigidBody->setup();
    for(int i=0;i<components.size();i++) components.at(i)->setup();
}

/*
template <class T> Component *GameObject::getComponent(){
    for(int i=0;i<components.size();i++){
        if( dynamic_cast<T>(components.at(i)) ) return components.at(i);
    }
    return NULL;
}
*/
 
void GameObject::setActive(bool b){
    active = b;
}

bool GameObject::isActive(){
    return active;
}

void GameObject::setParent(GameObject *g){
    if(parent != NULL){
        parent->removeChild(this);
    }
    bool isChidren = false;
    for(int i=0;i<g->children.size();i++){
        if(g->children.at(i) == this){
            isChidren = true; 
            break;
        }
    }
    if(!isChidren) g->addChild(this);
    parent = g;   
}

GameObject *GameObject::getParent(){
    return parent;
}

void GameObject::addChild(GameObject *g){
    children.push_back(g);
    if(g->getParent() != this) g->setParent(this);    
}

std::vector<GameObject*> GameObject::getChildren(){
    return children;
}

void GameObject::removeChild(GameObject* g){
    for(int i=0;i<children.size();i++){
        if(children.at(i) == g){
            children.erase(children.begin()+i);
            return;
        }
    }
}

Transform *GameObject::getTransform(){
    return transform;
}

RigidBody *GameObject::getRigidBody(){
    return rigidBody;
}

Renderer *GameObject::getRenderer(){
    return renderer;
}

Collider *GameObject::getCollider(){
    return collider;
}

void GameObject::onCollision(Collider* col) {
    
    if(getRigidBody() != NULL) getRigidBody()->onCollision(col);
    
    for(int i = components.size()-1; i >= 0; i--){
        if(components.at(i)->isActive()){
            if( dynamic_cast<Script*>(components.at(i)) )
                ((Script*)components.at(i))->onCollision(col);
        }
    }
}
