#ifndef OLEADA9_HPP
#define	OLEADA9_HPP

#include "../engine/GMEngine.hpp"

class oleada9: public gme::Scene {
public:
    oleada9(std::string s) : gme::Scene(s){
        reseting  = false;
    };

    virtual void setup();
    
    void setupBg();
    
    void setupScenario();

private:
    
    bool reseting;

};

#endif	/* OLEADA9_HPP */

