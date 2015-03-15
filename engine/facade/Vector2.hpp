#ifndef VECTOR2_HPP
#define	VECTOR2_HPP

#include <SFML/Graphics.hpp>

namespace gme{
    
class Vector2{
public:
    Vector2(float x = 0, float y = 0);
    float x, y;
    Vector2 normalized();
    float magnitude();
    float angle();
    float magnitude2();
    static float distance(Vector2 a, Vector2 b);
    Vector2 screenToWorld();
    Vector2 worldToScreen();
private:
    //sf::Vector2f vector;
};

}

#endif	/* VECTOR2_HPP */

