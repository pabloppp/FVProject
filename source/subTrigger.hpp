#ifndef SUBTRIGGER_HPP
#define	SUBTRIGGER_HPP

#include "../engine/GMEngine.hpp"

class subTrigger : public gme::Script {
public:
    subTrigger() : gme::Script(){};

    virtual void setup();
    virtual void update();
    virtual void onCollision(gme::Collider* c);


private:

};

#endif	/* SUBTRIGGER_HPP */

