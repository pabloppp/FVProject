#include "Vector2.hpp"
#include <math.h>

using namespace gme;


Vector2::Vector2(float nx, float ny) {
    //vector = sf::Vector2f(x, y);
    x = nx;
    y = ny;
}

Vector2 Vector2::normalized(){
    float l = sqrt(x*x + y*y);
    if(l != 0) return Vector2(x/l, y/l);
    else return Vector2(0, 0); 
}

float Vector2::magnitude(){
    return sqrt(x*x + y*y);
}

float Vector2::magnitude2(){
    return (x*x + y*y);
}

