#ifndef COLLISIONGRID_HPP
#define	COLLISIONGRID_HPP

#include "GameObject.hpp"


namespace gme{
    
class CollisionGrid {
public:
    CollisionGrid(){};
    CollisionGrid(float x, float y, float sx, float sy, float  = 4);
    void setLevel(int i);
    virtual ~CollisionGrid();
    void display();
    void addObject(GameObject *o);
    bool contains(GameObject *o);
    bool contains(float x, float y);
    void clear();
    std::vector<GameObject*> getObjectsAt(float x, float y);
private:
    int level;
    std::vector<CollisionGrid> nodes;
    std::vector<GameObject*> objects;
    float px, py, psx, psy;
};

}

#endif	/* COLLISIONGRID_HPP */

