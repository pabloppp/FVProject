#include "tileDestroyManager.hpp"

void tileDestroyManager::setup() {
    isHit = false;
    isHitTemp = false;
}

void tileDestroyManager::update() {
    if(isHitTemp == false) isHit = false;
    isHitTemp = false;
}

tileDestroyManager::~tileDestroyManager() {

}

void tileDestroyManager::onMessage(std::string m, float v) {
    
    if(m.compare("damage") == 0 && isHit == false){
        isHit = true;
        isHitTemp = true;
        hp -= v;
        if(hp <= 0){
            destroyGameObject(gameObject());
        }
    }
}


