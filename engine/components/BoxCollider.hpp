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
    void checkCollision(Collider *col);
    void render();
    Vector2 getSize();
private:
    sf::RectangleShape rectangle;
    Vector2 size;
};

}

#endif	/* BOXCOLLIDER_HPP */

