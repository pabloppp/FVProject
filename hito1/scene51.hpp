#ifndef SCENE51_HPP
#define	SCENE51_HPP

#include "../engine/GMEngine.hpp"

class scene51 : public gme::Scene {
public:
    scene51() : gme::Scene(){};
    scene51(std::string n) : gme::Scene(n){};
    void setup();
private:
    void setupLimits();
    void setupTileMap();

};

#endif	/* SCENE51_HPP */

