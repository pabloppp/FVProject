#ifndef LLBBEHAVIOR_HPP
#define	LLBBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"
#include "Animator.hpp"

class llbBehavior: public gme::Script {
public:
    llbBehavior() : gme::Script(){};
    virtual ~llbBehavior();
    void setup();
    void update();
private:
    Animator animator;
    gme::Clock clock;
};

#endif	/* LLBBEHAVIOR_HPP */

