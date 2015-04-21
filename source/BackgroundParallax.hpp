#ifndef BACKGROUNDPARALLAX_HPP
#define	BACKGROUNDPARALLAX_HPP

#include "../engine/GMEngine.hpp"

class BackgroundParallax : public gme::Script{
public:
    BackgroundParallax(): gme::Script(){};
    void setup();
    void update();
    virtual void fixedUpdate();
    virtual ~BackgroundParallax();
    float parallaxFactor;
private:
    gme::Transform *cameraTransform;
    gme::Vector2 initialPosition;
    gme::Vector2 initialDifference;
};

#endif	/* BACKGROUNDPARALLAX_HPP */

