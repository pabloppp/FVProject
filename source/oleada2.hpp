
#ifndef OLEADA2_HPP
#define	OLEADA2_HPP

#include "../engine/GMEngine.hpp"
class oleada2 : public gme::Scene {
public:
    oleada2(std::string s) : gme::Scene(s){
        reseting  = false;
    };

    virtual void setup();
    
    void setupBg();
    
    void setupScenario();

private:
    
    bool reseting;

};

#endif	/* OLEADA2_HPP */
