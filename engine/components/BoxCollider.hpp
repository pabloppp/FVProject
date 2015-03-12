#ifndef BOXCOLLIDER_HPP
#define	BOXCOLLIDER_HPP

#include "Collider.hpp"

namespace gme{

class BoxCollider : public Collider{
public:
    void setup();
    void update();
    void setSize(Vector2 s);
    void setSize(float x, float y);
    void render();
    std::vector<Vector2> getRotatedPoints();
    Vector2 getSize();
private:
    sf::ConvexShape rectangle;
    Vector2 size;
    b2PolygonShape b2shape;    
};

}

#endif	/* BOXCOLLIDER_HPP */

