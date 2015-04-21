
#ifndef INTROS1MANAGER_HPP
#define	INTROS1MANAGER_HPP

#include "../engine/GMEngine.hpp"

class IntroS1Manager : public gme::Script{
public:
    IntroS1Manager() : gme::Script() {};
    virtual ~IntroS1Manager();
    void setup();
    void update();
private:

};

#endif	/* INTROS1MANAGER_HPP */

