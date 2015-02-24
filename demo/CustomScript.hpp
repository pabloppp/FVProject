#ifndef CUSTOMSCRIPT_HPP
#define	CUSTOMSCRIPT_HPP

#include <iostream>
#include "../engine/GMEngine.hpp"

class CustomScript : public gme::Script{
public:
    void setup();
    void update();
    virtual ~CustomScript();
    void onGui();
    void onMessage(std::string s, float f);
private:
    float timeOut;
    float timeLapse;
    bool spaceDown;

};

#endif	/* CUSTOMSCRIPT_HPP */

