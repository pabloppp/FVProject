
#ifndef PBBEHAVIOR_HPP
#define	PBBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"

class pbBehavior: public gme::Script  {
public:
    pbBehavior() : gme::Script(){};
    virtual ~pbBehavior();
    void setup();
    void update();
private:
    gme::Vector2 winSize;
};

#endif	/* BULLETBEHAVIOR_HPP */

