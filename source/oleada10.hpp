
#ifndef OLEADA10_HPP
#define	OLEADA10_HPP

#include "../engine/GMEngine.hpp"
#include "generaPosicion.hpp"

class oleada10: public gme::Scene {
public:
    oleada10(std::string s) : gme::Scene(s){
        reseting  = false;
    };

    virtual void setup();
    
    void setupBg();
    
    void setupScenario();

private:
    generaPosicion *g;
    bool reseting;

};

#endif	/* OLEADA10_HPP */

