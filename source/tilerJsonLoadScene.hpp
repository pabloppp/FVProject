#ifndef TILERJSONLOADSCENE_HPP
#define	TILERJSONLOADSCENE_HPP

#include "../engine/GMEngine.hpp"

class tilerJsonLoadScene : public gme::Scene {
public:
    tilerJsonLoadScene(std::string s) : gme::Scene(s){};

    virtual void setup();
    
    void setupBg();

private:

};

#endif	/* TILERJSONLOADSCENE_HPP */

