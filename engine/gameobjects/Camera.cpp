#include "Camera.hpp"

using namespace gme;

void Camera::setup() {
    
}

gme::Vector2 Camera::getPosition(){
    return getTransform()->position;
}

void Camera::setPosition(gme::Vector2 p){
    getTransform()->setPosition(p);
}

void Camera::setPosition(float x, float y){
    getTransform()->setPosition(gme::Vector2(x, y));
}

gme::Vector2 Camera::getSize(){
    return getTransform()->scale;
}

void Camera::setSize(gme::Vector2 p){
    getTransform()->setScale(p);
}

void Camera::setSize(float x, float y){
    getTransform()->setScale(gme::Vector2(x, y));
}