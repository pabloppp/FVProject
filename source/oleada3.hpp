#ifndef OLEADA3_HPP
#define	OLEADA3_HPP
#include "../engine/GMEngine.hpp"

class oleada3: public gme::Scene {
public:
    oleada3(std::string s) : gme::Scene(s){
        reseting  = false;
    };

    virtual void setup();
    
    void setupBg();
    
    void setupScenario();

private:
    
    bool reseting;

};

#endif	/* OLEADA3_HPP */

