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
    virtual ~generaPosicion();
private:
    gme::Vector2 v;
    gme::Vector2 p;
    int posX;
    gme::Clock clk;
    sf::CircleShape area;
    gme::Window *w;
};

#endif	/* GENERAPOSICION_HPP */

