#ifndef MAINSCENE_HPP
#define	MAINSCENE_HPP

#include "../engine/GMEngine.hpp"

class mainScene : public gme::Scene{
public:
    mainScene() : gme::Scene(){};
    mainScene(std::string n) : gme::Scene(n){};
    void setup();
private:

};

#endif	/* MAINSCENE_HPP */

