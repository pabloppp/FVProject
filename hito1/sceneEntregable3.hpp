#ifndef SCENEENTREGABLE3_HPP
#define	SCENEENTREGABLE3_HPP

#include "../engine/GMEngine.hpp"

class sceneEntregable3 : public gme::Scene {
public:
    sceneEntregable3() : gme::Scene(){};
    sceneEntregable3(std::string n) : gme::Scene(n){};
    void setup();
private:

};

#endif	/* SCENEENTREGABLE3_HPP */

