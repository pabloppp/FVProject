#ifndef SMALLEXPLOSION_HPP
#define	SMALLEXPLOSION_HPP

#include "../engine/GMEngine.hpp"

class smallExplosion : public gme::Script {
public:
    smallExplosion() : gme::Script(){};
    void setup();
    void update();
    virtual ~smallExplosion();
private:
    gme::Clock reloj;
    int framecount;

};

#endif	/* SMALLEXPLOSION_HPP */

