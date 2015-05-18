#ifndef MOVETOTOP_HPP
#define	MOVETOTOP_HPP

#include "../engine/GMEngine.hpp"

class moveToTop : public gme::Script{
public:
    moveToTop() : gme::Script(){
        orderpostion = -1;
        automove = false;
        triggerMove = false;
    };
    void setOrder(int o);
    void setup();
    virtual void onMessage(std::string m, float v);
    void update();
    void move();
    bool automove;
    bool triggerMove;
private:
    gme::Clock doClock;
    int orderpostion;

};

#endif	/* MOVETOTOP_HPP */

