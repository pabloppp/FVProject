#include <stddef.h>

#include "Component.hpp"

using namespace gme;

Component::Component() {
    owner = NULL;
    active = true;
}

Component::Component(const Component& orig) {
}

Component::~Component() {
    
}

void Component::setActive(bool b){
    active = b;
}

bool Component::isActive(){
    return active;
}

GameObject *Component::gameObject(){
    return owner;
}

void Component::setGameObject(GameObject* g){
    owner = g;
}

