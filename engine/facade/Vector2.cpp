#include "Vector2.hpp"
#include <math.h>
#include "../Game.hpp"

using namespace gme;

#define PI  3.14159265 

Vector2::Vector2(float nx, float ny) {
    //vector = sf::Vector2f(x, y);
    x = nx;
    y = ny;
}

Vector2 Vector2::normalized(){
    float l = sqrt(x*x + y*y);
    if(l != 0) return Vector2(x/l, y/l);
    else return Vector2(0, 0); 
}

float Vector2::magnitude(){
    return sqrt(x*x + y*y);
}

float Vector2::magnitude2(){
    return (x*x + y*y);
}

float Vector2::angle() {
    return atan2(y,x)*180/PI;
}

float Vector2::distance(Vector2 a, Vector2 b) {
    float dx2 = b.x-a.x;
    dx2 *= dx2;
    float dy2 = b.y-a.y;
    dy2 *= dy2;
    return sqrtf(dx2+dy2);   
}

Vector2 Vector2::screenToWorld() {
    if(Game::mainCamera != NULL && Game::mainCamera->getTransform() != NULL){
        Vector2 windowSize = Game::getWindow()->getSize();
        Vector2 originalSize = Game::getWindow()->getOriginalSize();
        float stretchX = 1.f*originalSize.x/windowSize.x;
        float stretchY = 1.f*originalSize.y/windowSize.y;
        
        Vector2 res = Game::mainCamera->getTransform()->getPosition();
        return Vector2(x+res.x/stretchX, y+res.y/stretchY);
    }
    return Vector2(x, y);
}

Vector2 Vector2::worldToScreen() {
    if(Game::mainCamera != NULL && Game::mainCamera->getTransform() != NULL){
        Vector2 windowSize = Game::getWindow()->getSize();
        Vector2 originalSize = Game::getWindow()->getOriginalSize();
        float stretchX = 1.f*originalSize.x/windowSize.x;
        float stretchY = 1.f*originalSize.y/windowSize.y;
        
        Vector2 res = Game::mainCamera->getTransform()->getPosition();
        return Vector2(x-res.x/stretchX, y-res.y/stretchY);
    }
    return Vector2(x, y);
}



