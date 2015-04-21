#ifndef TILERJSONLOADSCENE_HPP
#define	TILERJSONLOADSCENE_HPP

#include "../engine/GMEngine.hpp"

class tilerJsonLoadScene : public gme::Scene {
public:
    tilerJsonLoadScene(std::string s) : gme::Scene(s){};

    virtual void setup();

private:

};

#endif	/* TILERJSONLOADSCENE_HPP */

