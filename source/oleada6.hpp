#ifndef OLEADA6_HPP
#define	OLEADA6_HPP
#include "../engine/GMEngine.hpp"
class oleada6: public gme::Scene {
public:
    oleada6(std::string s) : gme::Scene(s){
        reseting  = false;
    };

    virtual void setup();
    
    void setupBg();
    
    void setupScenario();

private:
    
    bool reseting;

};
#endif	/* OLEADA6_HPP */

