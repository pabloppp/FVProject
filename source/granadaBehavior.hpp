#ifndef GRANADABEHAVIOR_HPP
#define	GRANADABEHAVIOR_HPP

#include "../engine/GMEngine.hpp"

class granadaBehavior : public gme::Script {
public:
    granadaBehavior() : gme::Script(){
        whoami = 1;
        forceExplode = false;
    };
    void setup();
    void update();
    virtual ~granadaBehavior();

    virtual void onCollision(gme::Collider* c);

    int whoami;
private:
    gme::Clock timerClock;
    float timeToExplode;
    bool forceExplode;

};

#endif	/* GRANADABEHAVIOR_HPP */

