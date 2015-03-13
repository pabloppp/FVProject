#include "BoxCollider.hpp"

#include "../Game.hpp"
#include "CircleCollider.hpp"

#include <math.h>

#define SCALE 30.0f

using namespace gme;

void BoxCollider::setup(){
    Collider::setup();
    
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(1);
    rectangle.setPointCount(4);
    if(size.x == 0 || size.y == 0){
        setSize(60, 60);
    }
    
    canRotate = true;
    
    setFixture();
}

void BoxCollider::setFixture() {
    
    b2shape.SetAsBox((size.x/2.f)/SCALE, (size.y/2.f)/SCALE, b2Vec2(center.x, center.y), 0);
    
    fixtureDef.userData = this;
    fixtureDef.shape = &b2shape;
    
    if(gameObject()->getRigidBody() != NULL){        
        gameObject()->getRigidBody()->b2body->CreateFixture(&fixtureDef);
    }
}


void BoxCollider::update(){
    checked = false;
    if(gameObject()->getRigidBody() != NULL){
        for (b2ContactEdge *ce = gameObject()->getRigidBody()->b2body->GetContactList(); ce != NULL; ce = ce->next)
        {
            if(ce->contact->IsTouching()){
                BoxCollider *c = (BoxCollider*)(ce->contact->GetFixtureB()->GetUserData());
                if(c->gameObject() == gameObject()) c =(BoxCollider*)(ce->contact->GetFixtureA()->GetUserData());
                //if(!c->checkTags(this))
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
    //std::cout << "enters 1" << std::endl;
    if(gameObject() != NULL && gameObject()->getRigidBody() != NULL){       
        if(gameObject()->getRigidBody()->b2body->GetFixtureList()->GetNext()){
            b2Fixture *fixture = gameObject()->getRigidBody()->b2body->GetFixtureList();
            gameObject()->getRigidBody()->b2body->DestroyFixture(fixture);
            setup();
        }
    }
}

void BoxCollider::setCenter(float x, float y) {
    center = Vector2(1.f*x/SCALE, 1.f*y/SCALE);
    
    if(gameObject() != NULL && gameObject()->getRigidBody() != NULL){       
        if(gameObject()->getRigidBody()->b2body->GetFixtureList()->GetNext()){
            b2Fixture *fixture = gameObject()->getRigidBody()->b2body->GetFixtureList();
            gameObject()->getRigidBody()->b2body->DestroyFixture(fixture);
            setup();
        }
    }
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
    Vector2 p1(0,0);
    Vector2 p2(0,0);
    Vector2 p3(0,0);
    Vector2 p4(0,0);
    if(canRotate){

        float rot = transform.q.GetAngle();
        //std::cout << cA.x << std::endl;
        //rot = rot * (PI/180.f); 
        float x = -size.x/2;
        float y = -size.y/2;
        
        float centerX = cA.x*SCALE;
        float rCenterX = center.x*SCALE;
        float centerY = cA.y*SCALE;
        float rCenterY = center.y*SCALE;

        p1 = Vector2( centerX + ((rCenterX+x) * cos(rot)) - ((rCenterY+y) * sin(rot)) , centerY + ((rCenterX+x) * sin(rot)) + ((rCenterY+y) * cos(rot)));
        p2 = Vector2( centerX + ((rCenterX-x) * cos(rot)) - ((rCenterY+y) * sin(rot)) , centerY + ((rCenterX-x) * sin(rot)) + ((rCenterY+y) * cos(rot)));
        p3 = Vector2( centerX + ((rCenterX-x) * cos(rot)) - ((rCenterY-y) * sin(rot)) , centerY + ((rCenterX-x) * sin(rot)) + ((rCenterY-y) * cos(rot)));
        p4 = Vector2( centerX + ((rCenterX+x) * cos(rot)) - ((rCenterY-y) * sin(rot)) , centerY + ((rCenterX+x) * sin(rot)) + ((rCenterY-y) * cos(rot)));
    }
    
    rotatedPoints.push_back(p1);
    rotatedPoints.push_back(p2);
    rotatedPoints.push_back(p3);
    rotatedPoints.push_back(p4);
    
    return rotatedPoints;
}




