#ifndef SCENEPRUEBA_HPP
#define	SCENEPRUEBA_HPP

#include "../engine/GMEngine.hpp"

class scenePrueba: public gme::Scene {
public:
    scenePrueba() : gme::Scene(){};
    scenePrueba(std::string n) : gme::Scene(n){};
    void setup();
private:

};

#endif	/* SCENEPRUEBA_HPP */

