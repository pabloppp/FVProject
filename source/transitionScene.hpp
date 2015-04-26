#ifndef TRANSITIONSCENE_HPP
#define	TRANSITIONSCENE_HPP

#include "../engine/GMEngine.hpp"

class transitionScene : public gme::Scene {
public:
    transitionScene() : gme::Scene(){};
    transitionScene(std::string n) : gme::Scene(n){}
    void setup();
    static std::string nextScene;
private:

};

#endif	/* TRANSITIONSCENE_HPP */

