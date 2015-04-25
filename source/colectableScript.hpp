#ifndef COLECTABLESCRIPT_HPP
#define	COLECTABLESCRIPT_HPP

#include "../engine/GMEngine.hpp"


class ColectableScript : public gme::Script {
public:
    ColectableScript(int i) : gme::Script(){
        objectType=5;
    };
    virtual ~ColectableScript();
    void setup();
    void update();
    virtual void onCollision(gme::Collider* c);

private:
    gme::Clock clkD;
    int objectType;
    bool grounded;
};

#endif	/* COLECTABLESCRIPT_HPP */

