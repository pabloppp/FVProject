#ifndef LBBEHAVIOR_HPP
#define	LBBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"

class lbBehavior: public gme::Script {
public:
    lbBehavior() : gme::Script(){};
    void setup();
    void update();
    virtual ~lbBehavior();
private:
    gme::Vector2 winSize;
};

#endif	/* LBBEHAVIOR_HPP */

