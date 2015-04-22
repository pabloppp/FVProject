
#ifndef PBBEHAVIOR_HPP
#define	PBBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"

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
};

#endif	/* BULLETBEHAVIOR_HPP */

