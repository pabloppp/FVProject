#ifndef SBBEHAVIOR_HPP
#define	SBBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"
#include "GlobalStateManager.hpp"

class sbBehavior: public gme::Script {
public:
    sbBehavior() : gme::Script(){
        whoami = 1;
    };
    void setup();
    void update();
    virtual ~sbBehavior();
    virtual void onCollision(gme::Collider* c);
    
    int whoami;
private:
    gme::Vector2 winSize;
    bool destroy;
    gme::Clock myClock;
    gme::Clock animClock;
    int frame;
    GlobalStateManager *manager;
};

#endif	/* SBBEHAVIOR_HPP */

