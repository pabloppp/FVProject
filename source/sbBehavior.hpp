#ifndef SBBEHAVIOR_HPP
#define	SBBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"

class sbBehavior: public gme::Script {
public:
    sbBehavior() : gme::Script(){};
    void setup();
    void update();
    virtual ~sbBehavior();
private:
    gme::Vector2 winSize;
};

#endif	/* SBBEHAVIOR_HPP */

