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
    float magnitude2();
private:
    //sf::Vector2f vector;
};

}

#endif	/* VECTOR2_HPP */

