#ifndef SCENEENTREGABLE5_HPP
#define	SCENEENTREGABLE5_HPP

#include "../engine/GMEngine.hpp"

class sceneEntregable5 : public gme::Scene { 
public:
    sceneEntregable5() : gme::Scene(){};
    sceneEntregable5(std::string n) : gme::Scene(n){};
    void setup();
private:
    void setupTileMap();
};

#endif	/* SCENEENTREGABLE5_HPP */

