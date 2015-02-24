#ifndef PARTICLEDECAY_HPP
#define	PARTICLEDECAY_HPP

#include "../engine/GMEngine.hpp"

class particleDecay : public gme::Script{
public:
    void setup();
    void update();
    int frames;
    int fps;
    float elapsedTime;
private:
    int frameCount;
};

#endif	/* PARTICLEDECAY_HPP */

