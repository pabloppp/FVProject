
#ifndef SCENEENTREGABLE4_HPP
#define	SCENEENTREGABLE4_HPP

#include "../engine/GMEngine.hpp"

class sceneMenu : public gme::Scene{
public:
    sceneMenu() : gme::Scene(){};
    sceneMenu(std::string n) : gme::Scene(n){};
    void setup();
private:
   
};

#endif	/* SCENEENTREGABLE4_HPP */

