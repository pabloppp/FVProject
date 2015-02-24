#ifndef CIRCLECOLLIDER_HPP
#define	CIRCLECOLLIDER_HPP

#include "Collider.hpp"

namespace gme{

class CircleCollider : public Collider{
public:
    void setup();
    void update();
    void setRadius(float f);
    void checkCollision(Collider *col);
    void render();
    float getRadius();
private:
    sf::CircleShape circle;
    float radius;
};

}

#endif	/* CIRCLECOLLIDER_HPP */

