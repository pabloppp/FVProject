
#ifndef OLEADA5_HPP
#define	OLEADA5_HPP

#include "../engine/GMEngine.hpp"

class oleada5: public gme::Scene {
public:
    oleada5(std::string s) : gme::Scene(s){
        reseting  = false;
    };

    virtual void setup();
    
    void setupBg();
    
    void setupScenario();

private:
    
    bool reseting;

};

#endif	/* OLEADA5_HPP */
