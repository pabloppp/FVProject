#include "BoxCollider.hpp"

#include "../Game.hpp"
#include "CircleCollider.hpp"

#include <math.h>

#define SCALE 30.0f

using namespace gme;

void BoxCollider::setup(){
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(1);
    rectangle.setPointCount(4);
    if(size.x == 0 || size.y == 0){
        setSize(60, 60);
    }
    debugColor = sf::Color::Yellow;
    
    b2shape.SetAsBox((size.x/2.f)/SCALE, (size.y/2.f)/SCALE);
    fixtureDef.shape = &b2shape;
    fixtureDef.density = 1.f;
    fixtureDef.userData = this;
    if(gameObject()->getRigidBody() != NULL){
        fixtureDef.density = gameObject()->getRigidBody()->fixtureDef.density;
        gameObject()->getRigidBody()->b2body->CreateFixture(&fixtureDef);
        fixtureDef.friction = gameObject()->getRigidBody()->getFriction();
        fixtureDef.restitution = gameObject()->getRigidBody()->getElasticity();
    }
    canRotate = true;
}

void BoxCollider::update(){
    checked = false;
    if(gameObject()->getRigidBody() != NULL){
        for (b2ContactEdge *ce = gameObject()->getRigidBody()->b2body->GetContactList(); ce != NULL; ce = ce->next)
        {
            if(ce->contact->IsTouching()){
                BoxCollider *c = (BoxCollider*)(ce->contact->GetFixtureA()->GetUserData());
                if(!c->checkTags(this))
                    noticeCollision(c);
            }
        }
    }
    if(!colliding){
        debugColor = sf::Color::Yellow;
    }
    colliding = false;

}

void BoxCollider::setSize(Vector2 s){
    size = s;
}

void BoxCollider::setSize(float x, float y){
    setSize(Vector2(x, y));
}


void BoxCollider::render(){

    std::vector<Vector2> points = getRotatedPoints();
   

    rectangle.setPoint(0, sf::Vector2f(points.at(0).x, points.at(0).y));
    rectangle.setPoint(1, sf::Vector2f(points.at(1).x, points.at(1).y));
    rectangle.setPoint(2, sf::Vector2f(points.at(2).x, points.at(2).y));
    rectangle.setPoint(3, sf::Vector2f(points.at(3).x, points.at(3).y));
    rectangle.setOutlineColor(debugColor); 
    
    Game::getWindow()->draw(rectangle);
    
}

Vector2 BoxCollider::getSize(){
    return size;
}

std::vector<Vector2> BoxCollider::getRotatedPoints() {
    
    b2PolygonShape *shape = (b2PolygonShape*)(gameObject()->getRigidBody()->b2body->GetFixtureList()->GetNext()->GetShape());
    b2Transform transform = gameObject()->getRigidBody()->b2body->GetTransform();
    
    std::vector<Vector2> rotatedPoints;
    Vector2 cA = Vector2(gameObject()->getRigidBody()->b2body->GetPosition().x, gameObject()->getRigidBody()->b2body->GetPosition().y); 
    Vector2 p1(cA.x+shape->GetVertex(0).x, cA.y+shape->GetVertex(0).y);
    Vector2 p2(cA.x+shape->GetVertex(1).x, cA.y+shape->GetVertex(1).y);
    Vector2 p3(cA.x+shape->GetVertex(2).x, cA.y+shape->GetVertex(2).y);
    Vector2 p4(cA.x+shape->GetVertex(3).x, cA.y+shape->GetVertex(3).y);
    if(canRotate){

        float rot = transform.q.GetAngle();
        //std::cout << cA.x << std::endl;
        //rot = rot * (PI/180.f); 
        float x = -size.x/2;
        float y = -size.y/2;

        p1 = Vector2(cA.x*SCALE + (x * cos(rot)) - (y * sin(rot)) , cA.y*SCALE + (x * sin(rot)) + (y * cos(rot)));
        p2 = Vector2(cA.x*SCALE + (-x * cos(rot)) - (y * sin(rot)) , cA.y*SCALE + (-x * sin(rot)) + (y * cos(rot)));
        p3 = Vector2(cA.x*SCALE + (-x * cos(rot)) - (-y * sin(rot)) , cA.y*SCALE + (-x * sin(rot)) + (-y * cos(rot)));
        p4 = Vector2(cA.x*SCALE + (x * cos(rot)) - (-y * sin(rot)) , cA.y*SCALE + (x * sin(rot)) + (-y * cos(rot)));
    }
    
    rotatedPoints.push_back(p1);
    rotatedPoints.push_back(p2);
    rotatedPoints.push_back(p3);
    rotatedPoints.push_back(p4);
    
    return rotatedPoints;
}




