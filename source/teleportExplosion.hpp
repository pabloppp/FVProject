#ifndef TELEPORTEXPLOSION_HPP
#define	TELEPORTEXPLOSION_HPP

#include "../engine/GMEngine.hpp"

class teleportExplosion : public gme::Script{
public:
    teleportExplosion() : gme::Script(){};
    void setup();
    void update();
    virtual ~teleportExplosion();
private:
    gme::Clock reloj;
    int framecount;
};

#endif	/* TELEPORTEXPLOSION_HPP */

