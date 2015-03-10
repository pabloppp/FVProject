#include "CollisionGrid.hpp"

#include "Game.hpp"
#include "components/CircleCollider.hpp"
#include "components/BoxCollider.hpp"

using namespace gme;

CollisionGrid::CollisionGrid(float x, float y, float sx, float sy, float subd) {
    level = subd; 
    px = x;
    py = y;
    psx = sx;
    psy = sy;
    if(level > 0){
        CollisionGrid c1(x,y,sx/2.0,sy/2.0, level-1);
        CollisionGrid c2(x+sx/2.0,y,sx/2.0,sy/2.0, level-1);
        CollisionGrid c3(x,y+sy/2.0,sx/2.0,sy/2.0, level-1);
        CollisionGrid c4(sx/2.0+x,sy/2.0+y,sx/2.0,sy/2.0, level-1);
        nodes.push_back(c1);
        nodes.push_back(c2);
        nodes.push_back(c3);
        nodes.push_back(c4);
    }
}

CollisionGrid::~CollisionGrid() {

}

void CollisionGrid::setLevel(int i) {
    level = i;
}

void CollisionGrid::addObject(GameObject* o) {
    if(level == 0){
        objects.push_back(o);
    }
    else{
        for(int i=0;i<4;i++){
            if(nodes.at(i).contains(o)) nodes.at(i).addObject(o);
        }
    }
}

bool CollisionGrid::contains(GameObject* o) {
    gme::Vector2 oPosition = o->getTransform()->position;
    gme::Vector2 size(0,0);
    if(dynamic_cast<gme::CircleCollider*>(o->getCollider())){
        size.x = ((gme::CircleCollider*)(o->getCollider()))->getRadius();
        size.y = size.x;
    }
    if(dynamic_cast<gme::BoxCollider*>(o->getCollider())){
        size.x = 0;
        size.y = size.x;
    }
    float o_left = oPosition.x-size.x;
    float o_right = oPosition.x+size.x;
    float o_top = oPosition.y-size.y;
    float o_down = oPosition.y+size.y;
    
    if(o_left <= px+psx && o_right > px && o_top <= py+psy && o_down > py) return true;
    return false;
}

bool CollisionGrid::contains(float x, float y) {
    if(x <= px+psx && x > px && y <= py+psy && y > py) return true;
    return false;
}

std::vector<GameObject*> CollisionGrid::getObjectsAt(float x, float y) {
    if(level == 0) return objects;
    
    std::vector<gme::GameObject*> returnedObjects;
    std::vector<gme::GameObject*> childObjects;
    
    for (int n=0;n<4; ++n ) {
        if (nodes[n].contains( x, y ) ) {
            childObjects = nodes[n].getObjectsAt(x, y);
            returnedObjects.insert( returnedObjects.end(), childObjects.begin(), childObjects.end() );
            break;
        }
    }
    
    return returnedObjects;
}


void CollisionGrid::display(){
    if(level == 0){
        sf::RectangleShape rs;
        rs.setPosition(px, py);
        rs.setSize(sf::Vector2f(psx, psy));
        rs.setFillColor(sf::Color::Transparent);
        rs.setOutlineColor(sf::Color(150,200,255,100));
        rs.setOutlineThickness(0.5);
        Game::getWindow()->draw(rs);
    }
    else{
        for(int i=0;i<4;i++) nodes.at(i).display();
    }
}

void CollisionGrid::clear() {
    objects.clear();
    if(level != 0){
        for(int i=0;i<4;i++) nodes.at(i).clear();
    }
}





