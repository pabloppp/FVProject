#ifndef TRANSFORM_HPP
#define	TRANSFORM_HPP

#include <SFML/Graphics.hpp>
#include "../Component.hpp"
#include "../facade/Vector2.hpp"

namespace gme{

class Transform : public Component{
public:
    gme::Vector2 getPosition();
    gme::Vector2 getPositionRelative();
    float getRotation();
    float getRotationRelative();
    gme::Vector2 getScale();
    gme::Vector2 getScaleRelative();
    float getZIndex();
    void setPosition(gme::Vector2 v);
    void setRotation(float f);
    void setScale(gme::Vector2 v);
    void setZIndex(float i);
    void rotate(float i);
    void resize(gme::Vector2 v);
    void translate(gme::Vector2 v);
    void translate(gme::Vector2 dir, float dist);
    void lookAt(GameObject *g);
    void setup();
    void update();
    gme::Vector2 position;
    gme::Vector2 o_position;
    float rotation;
    float o_rotation;
    gme::Vector2 scale;
    gme::Vector2 o_scale;
    gme::Vector2 forward();
private:
    float zIndex;
};

}

#endif	/* TRANSFORM_HPP */

