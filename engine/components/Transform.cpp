#include "Transform.hpp"

#include "../GameObject.hpp"
#include <math.h>

using namespace gme;

gme::Vector2 Transform::getPosition(){
    gme::Vector2 v = position;
    if(gameObject()!= NULL && gameObject()->getParent() != NULL){
        v.x += gameObject()->getParent()->getTransform()->getPosition().x;
        v.y += gameObject()->getParent()->getTransform()->getPosition().y;
    }
    return v;
}

gme::Vector2 Transform::getPositionRelative(){
    return position;
}

float Transform::getRotation(){
    float f = rotation;
    if(gameObject()!= NULL && gameObject()->getParent() != NULL){
        f += gameObject()->getParent()->getTransform()->getRotation();
    }
    return rotation;
}

float Transform::getRotationRelative(){
    return rotation;
}

gme::Vector2 Transform::getScale(){
    gme::Vector2 v = scale;
    if(gameObject()!= NULL && gameObject()->getParent() != NULL){
        v.x *= gameObject()->getParent()->getTransform()->getScale().x;
        v.y *= gameObject()->getParent()->getTransform()->getScale().y;
    }
    return v;
}

gme::Vector2 Transform::getScaleRelative(){
    return scale;
}

float Transform::getZIndex(){
    return zIndex;
}

void Transform::setPosition(gme::Vector2 v){
  position = v;  
}

void Transform::setRotation(float f){
  rotation = f;  
}

void Transform::setScale(gme::Vector2 v){
  scale = v;  
}

void Transform::setZIndex(float f){
    zIndex = f;
}

void Transform::rotate(float i){
    rotation += i;
}

void Transform::resize(gme::Vector2 v){
    scale.x *= v.x;
    scale.y *= v.y;
}

void Transform::translate(gme::Vector2 v){
    position.x += v.x;
    position.y += v.y;
}

void Transform::lookAt(GameObject* g){
    //TO DO
}

void Transform::setup(){
    if(scale.x == 0 || scale.y == 0){
        scale = gme::Vector2(1,1);
    }
}

Vector2 Transform::forward(){
    float PI = 3.14159265;
    return Vector2(sin(rotation*PI/180), -cos(rotation*PI/180));
}

void Transform::update(){
    
}

