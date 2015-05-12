#ifndef LLBBEHAVIOR_HPP
#define	LLBBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"
#include "Animator.hpp"
#include "GlobalStateManager.hpp"

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
    gme::Clock animclock;
    int frame;
    int initialXSpeed;
    bool destroy;
    gme::Vector2 winSize;
    GlobalStateManager *manager;
};

#endif	/* LLBBEHAVIOR_HPP */

