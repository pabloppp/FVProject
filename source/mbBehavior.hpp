#ifndef MBBEHAVIOR_HPP
#define	MBBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"

class mbBehavior: public gme::Script {
public:
    mbBehavior() : gme::Script(){};
    void setup();
    void update();
    virtual ~mbBehavior();
private:
    gme::Vector2 winSize;
};

#endif	/* MBBEHAVIOR_HPP */

