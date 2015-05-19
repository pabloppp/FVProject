
#ifndef OLEADA7_HPP
#define	OLEADA7_HPP

#include "../engine/GMEngine.hpp"
#include "generaPosicion.hpp"

class oleada7: public gme::Scene {
public:
    oleada7(std::string s) : gme::Scene(s){
        reseting  = false;
    };

    virtual void setup();
    
    void setupBg();
    
    void setupScenario();

private:
    generaPosicion *g;
    bool reseting;

};

#endif	/* OLEADA7_HPP */

