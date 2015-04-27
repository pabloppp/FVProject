#ifndef LLBBEHAVIOR_HPP
#define	LLBBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"
#include "Animator.hpp"

class llbBehavior: public gme::Script {
public:
    llbBehavior() : gme::Script(){};
    virtual ~llbBehavior();
    void setup();
    void update();
    virtual void onCollision(gme::Collider* c);
private:
    Animator animator;
    gme::Clock clock;
    bool destroy;
    gme::Vector2 winSize;
};

#endif	/* LLBBEHAVIOR_HPP */

