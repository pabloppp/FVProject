#ifndef MBBEHAVIOR_HPP
#define	MBBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"
#include "GlobalStateManager.hpp"

class mbBehavior: public gme::Script {
public:
    mbBehavior() : gme::Script(){
         whoami = 1;
    };
    void setup();
    void update();
    virtual ~mbBehavior();
    virtual void onCollision(gme::Collider* c);
    int whoami;
    
private:
    gme::Vector2 winSize;
    bool destroy;
    gme::Clock myClock;
    GlobalStateManager *manager;
};

#endif	/* MBBEHAVIOR_HPP */

