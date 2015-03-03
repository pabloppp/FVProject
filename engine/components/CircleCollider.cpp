#include "CircleCollider.hpp"
#include "Transform.hpp"

#include "../Game.hpp"
#include "BoxCollider.hpp"

using namespace gme;

void CircleCollider::setup(){
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(1);
    if(radius == 0) setRadius(30);
    debugColor = sf::Color::Yellow;
}

void CircleCollider::update(){ //Check collisions
    //reset debug color
    if(!colliding){
        debugColor = sf::Color::Yellow;
    }
    if(colliding){
        colliding = false;
    }
}

void CircleCollider::setRadius(float f){
    radius = f;
    circle.setOrigin(radius, radius);
    circle.setRadius(radius);;
}

float CircleCollider::getRadius(){
    return radius;
}

void CircleCollider::checkCollision(Collider* col){
    if(checkTags(col) || col->checkTags(this)) return;
    if(dynamic_cast<CircleCollider*>(col)){
        Vector2 cA = getGlobalCenter();
        Vector2 cB = col->getGlobalCenter();
        float rA = radius;
        float rB = ((CircleCollider*)col)->radius;
        
        Vector2 AB(cB.x-cA.x, cB.y-cA.y);
        float d2 = AB.magnitude2();
        float r2 = (rA+rB)*(rA+rB);
        
        if(d2 < r2){
            noticeCollision(col);
            col->noticeCollision(this);
        }
        
    }
    else if(dynamic_cast<BoxCollider*>(col)){
        
    }
}

void CircleCollider::render(){
    //std::cout << "collider update" << std::endl;
    Vector2 pos = getGlobalCenter();
    circle.setPosition(pos.x, pos.y);
    circle.setOutlineColor(debugColor);
    Game::getWindow()->draw(circle);
}

