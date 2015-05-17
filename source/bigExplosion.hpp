#ifndef BIGEXPLOSION_HPP
#define	BIGEXPLOSION_HPP

#include "../engine/GMEngine.hpp"

class bigExplosion : public gme::Script {
public:
    bigExplosion() : gme::Script(){
        whoami = 1;
    };
    void setup();
    void update();
    virtual ~bigExplosion();

    virtual void onCollision(gme::Collider* c);
    int whoami;
private:
    gme::Clock reloj, boomClock;
    int framecount;
    bool exploded;
};

#endif	/* BIGEXPLOSION_HPP */

