/* 
 * File:   generaPosicion.hpp
 * Author: albertomartinezmartinez
 *
 * Created on 28 de febrero de 2015, 12:38
 */

#ifndef GENERAPOSICION_HPP
#define	GENERAPOSICION_HPP

#include "../engine/GMEngine.hpp"

class generaPosicion : public gme::Script {
public:
    void setup();
    void update();
    void position(int x, int y,int rat);
    virtual void onGui();
    virtual ~generaPosicion();
private:
    gme::Vector2 v;
    double angle;
    gme::Clock clk;
    sf::CircleShape ratio;
    gme::Window *w;
};

#endif	/* GENERAPOSICION_HPP */

