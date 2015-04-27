#ifndef MOVETOTOP_HPP
#define	MOVETOTOP_HPP

#include "../engine/GMEngine.hpp"

class moveToTop : public gme::Script{
public:
    void setup();
    void update();
private:
    gme::Clock doClock;

};

#endif	/* MOVETOTOP_HPP */

