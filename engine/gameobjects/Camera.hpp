#ifndef CAMERA_HPP
#define	CAMERA_HPP

#include "../GMEngine.hpp"

namespace gme{
    
class Camera : public gme::GameObject{
public:
    Camera(std::string n) : gme::GameObject(n){};
    void setup();
    gme::Vector2 getPosition();
    void setPosition(gme::Vector2 p);
    void setPosition(float x, float y);
    gme::Vector2 getSize();
    void setSize(gme::Vector2 p);
    void setSize(float x, float y);
private:

};

}

#endif	/* CAMERA_HPP */

