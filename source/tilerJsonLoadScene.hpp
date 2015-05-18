#ifndef TILERJSONLOADSCENE_HPP
#define	TILERJSONLOADSCENE_HPP

#include "../engine/GMEngine.hpp"
#include "generaPosicion.hpp"
#include "Animator.hpp"

class tilerJsonLoadScene : public gme::Scene {
public:
    tilerJsonLoadScene(std::string s) : gme::Scene(s){
        reseting  = false;
    };

    virtual void setup();
    void setupBg();
    
    void setupScenario();

private:
    generaPosicion *g;
    bool reseting;

};

#endif	/* TILERJSONLOADSCENE_HPP */

