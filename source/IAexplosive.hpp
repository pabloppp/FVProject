#ifndef IAEXPLOSIVE_HPP
#define	IAEXPLOSIVE_HPP

#include "../engine/GMEngine.hpp"
#include "GlobalStateManager.hpp"

class IAexplosive : public gme::Script {
public:
    IAexplosive() :gme::Script(){
        gonnaExplode = false;
        exploded = false;
        iam = 0;
    };
    void setup();
    void update();

    virtual void onMessage(std::string m, float v);
    
    void explode();

private:
    bool gonnaExplode, exploded;
    gme::Clock countdownClock;
    int iam;
    
};

#endif	/* IAEXPLOSIVE_HPP */

