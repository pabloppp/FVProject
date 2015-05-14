#ifndef COLECTABLESCRIPT_HPP
#define	COLECTABLESCRIPT_HPP

#include "../engine/GMEngine.hpp"


class ColectableScript : public gme::Script {
public:
    ColectableScript(int i) : gme::Script(){
        objectType=i;
    };
    virtual ~ColectableScript();
    void setup();
    void update();
    virtual void onCollision(gme::Collider* c);
    virtual void onGui();
    void animate();
    void explode(int min, int max, float forcemin, float forcemax);
    int hp;

private:
    gme::Clock clkD;
    gme::Clock animClock;
    int walkFrameCountFD;
    int walkFrameCountPD;
    int walkFrameCountL;
    int walkFPS; 
    int objectType;
    bool grounded;
    bool destroyed;
    bool isHit;
    virtual void onMessage(std::string m, float v);
};

#endif	/* COLECTABLESCRIPT_HPP */

