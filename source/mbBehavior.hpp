#ifndef MBBEHAVIOR_HPP
#define	MBBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"
#include "GlobalStateManager.hpp"

class mbBehavior: public gme::Script {
public:
    mbBehavior() : gme::Script(){};
    void setup();
    void update();
    virtual ~mbBehavior();
    virtual void onCollision(gme::Collider* c);
    
private:
    gme::Vector2 winSize;
    bool destroy;
    gme::Clock myClock;
    GlobalStateManager *manager;
};

#endif	/* MBBEHAVIOR_HPP */

