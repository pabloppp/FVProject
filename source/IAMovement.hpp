/* 
 * File:   IAMovement.hpp
 * Author: albertomartinezmartinez
 *
 * Created on 14 de abril de 2015, 18:18
 */

#ifndef IAMOVEMENT_HPP
#define	IAMOVEMENT_HPP

#include "../engine/GMEngine.hpp"

class IAMovement : public gme::Script {
public:
    IAMovement() : gme::Script(){};
    void setup();
    void update();
    void findPlayer();   
    void vectorDirector(gme::Vector2 player, gme::Vector2 enemy);
    virtual ~IAMovement();
private:
    gme::GameObject *player;
    gme::Clock clk;
    gme::Vector2 dir = gme::Vector2(1,0);
    bool right;
   

};

#endif	/* IAMOVEMENT_HPP */

