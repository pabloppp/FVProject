#include "BoxCollider.hpp"

#include "../Game.hpp"
#include "CircleCollider.hpp"

using namespace gme;

void BoxCollider::setup(){
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(1);
    if(size.x == 0 || size.y == 0)  setSize(60, 60);
    debugColor = sf::Color::Yellow;
}

void BoxCollider::update(){
    if(!colliding) debugColor = sf::Color::Yellow;
    colliding = false;
}

void BoxCollider::setSize(Vector2 s){
    size = s;
    rectangle.setSize(sf::Vector2f(s.x, s.y));
    rectangle.setOrigin(s.x/2, s.y/2);
}

void BoxCollider::setSize(float x, float y){
    setSize(Vector2(x, y));
}

void BoxCollider::checkCollision(Collider* col){
    if(checkTags(col) || col->checkTags(this)) return;
    if(dynamic_cast<BoxCollider*>(col)){
        
    }
    else if(dynamic_cast<CircleCollider*>(col)){
        
    }
}

void BoxCollider::render(){
    Vector2 pos = getGlobalCenter();
    float rot = gameObject()->getTransform()->getRotation();
    if(canRotate && gameObject() != NULL){
        rectangle.setRotation(rot);
    }
    rectangle.setPosition(pos.x, pos.y);
    rectangle.setOutlineColor(debugColor);   
    Game::getWindow()->draw(rectangle);
}

Vector2 BoxCollider::getSize(){
    return size;
}



