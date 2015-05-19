#ifndef OLEADA8_HPP
#define	OLEADA8_HPP

#include "../engine/GMEngine.hpp"
#include "generaPosicion.hpp"

class oleada8: public gme::Scene {
public:
    oleada8(std::string s) : gme::Scene(s){
        reseting  = false;
    };

    virtual void setup();
    
    void setupBg();
    
    void setupScenario();

private:
    generaPosicion *g;
    bool reseting;

};

#endif	/* OLEADA8_HPP */

