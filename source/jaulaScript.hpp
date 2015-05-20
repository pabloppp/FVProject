#ifndef JAULASCRIPT_HPP
#define	JAULASCRIPT_HPP

#include "../engine/GMEngine.hpp"

class jaulaScript : public gme::Script  {
public:
    jaulaScript() : gme::Script(){
        moving = false;
        frame = 0;
    };
    void setup();
    void update();

    virtual void onCollision(gme::Collider* c);

    virtual ~jaulaScript();
private:
    bool moving;
    int frame;
    gme::Clock reloj;
};

#endif	/* JAULASCRIPT_HPP */

