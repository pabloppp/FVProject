#ifndef OLEADA4_HPP
#define	OLEADA4_HPP

#include "../engine/GMEngine.hpp"

class oleada4 : public gme::Scene{
public:
    oleada4(std::string s) : gme::Scene(s){
        reseting  = false;
    };

    virtual void setup();
    
    void setupBg();
    
    void setupScenario();

private:
    
    bool reseting;

};

#endif	/* OLEADA4_HPP */

