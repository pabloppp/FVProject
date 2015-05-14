#ifndef MOVETOTOP_HPP
#define	MOVETOTOP_HPP

#include "../engine/GMEngine.hpp"

class moveToTop : public gme::Script{
public:
    moveToTop() : gme::Script(){
        orderpostion = -1;
        automove = false;
    };
    void setOrder(int o);
    void setup();
    void update();
    void move();
    bool automove;
private:
    gme::Clock doClock;
    int orderpostion;

};

#endif	/* MOVETOTOP_HPP */

