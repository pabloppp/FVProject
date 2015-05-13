#ifndef MYMENU_HPP
#define	MYMENU_HPP

#include "../engine/GMEngine.hpp"

class myMenu: public gme::GameObject {
public:
    myMenu(std::string n) : gme::GameObject(n){};
    void setup();
private:

};

#endif	/* MYMENU_HPP */

