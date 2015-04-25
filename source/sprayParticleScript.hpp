#ifndef SPRAYPARTICLESCRIPT_HPP
#define	SPRAYPARTICLESCRIPT_HPP

#include "../engine/GMEngine.hpp"

class sprayParticleScript : public gme::Script {
public:
    virtual void setup();

    virtual void update();
    
    virtual ~sprayParticleScript();


    virtual void onCollision(gme::Collider* c);

    bool sticky;

private:
    
    int minDuration; //segundos
    int maxDuration; 
    int duration;
    gme::Clock lifeClock;

};

#endif	/* SPRAYPARTICLESCRIPT_HPP */

