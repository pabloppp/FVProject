#include "Collider.hpp"
#include "Transform.hpp"

#include "../GameObject.hpp"
#include "math.h"

using namespace gme;

void Collider::addFilterTag(const std::string& tag){
    tags.push_back(tag);
}

void Collider::removeFilterTag(const std::string& tag){
    for(int i=0;i<tags.size();i++){
        if(tags.at(i).compare(tag) == 0){
            tags.erase(tags.begin()+i);
            return;
        }
    }
}

void Collider::inheritRotation(bool b){
    canRotate = b;
}

Vector2 Collider::getGlobalCenter(){
    float PI = 3.14159265;
    float rot = gameObject()->getTransform()->getRotation();
    float cosRot = cos(rot*PI/180);
    float sinRot = sin(rot*PI/180);
    //std::cout << rot << " : " << cosRot << std::endl;
    Vector2 c(cosRot*center.x-sinRot*(-center.y), cosRot*(-center.y)+sinRot*center.x);
    
    if(gameObject() != NULL){
        c.x += gameObject()->getTransform()->position.x;
        c.y += gameObject()->getTransform()->position.y;
    }
    return c;
}

void Collider::noticeCollision(Collider* col){
    debugColor = sf::Color::Red;
    colliding = true;
}

bool Collider::checkTags(Collider *col){
    if(gameObject() != NULL && col->gameObject() != NULL){
        for(int i=0;i<tags.size();i++){
            for(int j=0;j<col->gameObject()->getTags()->size();j++){
                if(tags.at(i).compare(col->gameObject()->getTags()->at(j)) == 0) return true;
            }
        }
    }
    return false;
}

