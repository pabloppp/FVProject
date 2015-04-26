#ifndef TILERJSONLOADSCENE_HPP
#define	TILERJSONLOADSCENE_HPP

#include "../engine/GMEngine.hpp"

class tilerJsonLoadScene : public gme::Scene {
public:
    tilerJsonLoadScene(std::string s) : gme::Scene(s){
        reseting  = false;
    };

    virtual void setup();
    
    void setupBg();
    
    void setupScenario();

private:
    
    bool reseting;

};

#endif	/* TILERJSONLOADSCENE_HPP */

