
#ifndef SHOTSCRIPT_HPP
#define	SHOTSCRIPT_HPP

#include "../engine/GMEngine.hpp"


class ShotScript : public gme::Script{
public:
    ShotScript() : gme::Script(){
        ShotKey = gme::Keyboard::G;
        keyUp = gme::Keyboard::W;
        keyLeft = gme::Keyboard::A;
        keyRight = gme::Keyboard::D;
    };
    virtual ~ShotScript();
    void setup();
    void update();   
    //virtual void onCollision(gme::Collider *c);
    gme::Keyboard::Key ShotKey;
    gme::Keyboard::Key keyUp;
    gme::Keyboard::Key keyLeft;
    gme::Keyboard::Key keyRight;
private:
    bool disparado;
};

#endif	/* SHOTSCRIPT_HPP */

