#include <unordered_map>

#include "Collider.hpp"
#include "Transform.hpp"

#include "../GameObject.hpp"
#include "math.h"
#include "BoxCollider.hpp"
#define PI  3.14159265 

using namespace gme;

void Collider::addFilterTag(const std::string& tag){
    tagmap.insert(std::pair<std::string, std::string>(tag, tag));
}

void Collider::removeFilterTag(const std::string& tag){
    tagmap.erase(tag);
}

void Collider::inheritRotation(bool b){
    canRotate = b;
}

Vector2 Collider::getGlobalCenter(){
    
    return gameObject()->getTransform()->position;
    
}

void Collider::noticeCollision(Collider* col){
    debugColor = sf::Color::Red;
    colliding = true;
    gameObject()->onCollision(col);
}

bool Collider::checkTags(Collider *col){
    if(gameObject() != NULL && col->gameObject() != NULL){
        for ( auto it = tagmap.begin(); it != tagmap.end(); ++it ){
            if(col->gameObject()->getTags()->find(it->second) != col->gameObject()->getTags()->end()) return true;
        }
    }
    return false;
}

void Collider::isTrigger(bool b) {
    
    if(gameObject() != NULL && gameObject()->getRigidBody() != NULL){
        int count = 0;
        for (b2Fixture *ce = gameObject()->getRigidBody()->b2body->GetFixtureList(); ce != NULL; ce = ce->GetNext())
        {
            if(count == 0) ce->SetSensor(b);
        }
    }
    else{
        fixtureDef.isSensor = b;
    }
}

Vector2 Collider::getRelativePosition(Collider* col) {    
    Vector2 positionA = gameObject()->getTransform()->position;
    Vector2 positionB = col->gameObject()->getTransform()->position;
    Vector2 sizeA(0,0);
    Vector2 sizeB(0,0);
    float r = col->gameObject()->getTransform()->rotation;
    r = r*PI/180.f;
    if(dynamic_cast<BoxCollider*>(this)){
        std::vector<Vector2> points = ((BoxCollider*)(this))->getRotatedPoints();
        for(int i=0;i<4;i++){
            if(points.at(i).x-positionA.x > sizeA.x) sizeA.x = points.at(i).x-positionA.x;
            if(points.at(i).y-positionA.y > sizeA.y) sizeA.y = points.at(i).y-positionA.y;
        }
    }
    
    if(dynamic_cast<BoxCollider*>(col)){
        std::vector<Vector2> points = ((BoxCollider*)(col))->getRotatedPoints();
        for(int i=0;i<4;i++){
            if(points.at(i).x-positionB.x > sizeB.x) sizeB.x = points.at(i).x-positionB.x;
            if(points.at(i).y-positionB.y > sizeB.y) sizeB.y = points.at(i).y-positionB.y;
        }
    }
    
    Vector2 result(0,0);
    
    if(positionA.y+sizeA.y/2.f < positionB.y-sizeB.y/2.f) result.y = -1;
    else if(positionA.y-sizeA.y/2.f > positionB.y+sizeB.y/2.f) result.y = 1;
    
    if(positionA.x+sizeA.x/2.f < positionB.x-sizeB.x/2.f) result.x = -1;
    else if(positionA.x-sizeA.x/2.f > positionB.x+sizeB.x/2.f) result.x = 1;  
        
    return result;
}


