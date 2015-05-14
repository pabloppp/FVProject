
#ifndef PBBEHAVIOR_HPP
#define	PBBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"
#include "GlobalStateManager.hpp"

class pbBehavior: public gme::Script  {
public:
    pbBehavior() : gme::Script(){};
    virtual ~pbBehavior();
    void setup();
    void update();

    virtual void onCollision(gme::Collider* c);

private:
    bool destroy;
    gme::Clock myClock;
    gme::Vector2 winSize;
    GlobalStateManager *manager;
};

#endif	/* BULLETBEHAVIOR_HPP */

