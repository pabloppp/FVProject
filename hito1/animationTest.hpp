#ifndef ANIMATIONTEST_HPP
#define	ANIMATIONTEST_HPP

#include "../engine/GMEngine.hpp"
#include "Animator.hpp"

class animationTest : public gme::Script{
public:
    animationTest() : gme::Script(){};
    void setup();
    void update();
private:
    Animator animator;
    gme::Keyboard::Key pauseKey;
    gme::Keyboard::Key resumeKey;
    bool paused;
};

#endif	/* ANIMATIONTEST_HPP */

