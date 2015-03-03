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
    virtual ~generaPosicion();
private:
    gme::Vector2 v;
    int posX;
    gme::Clock clk;
};

#endif	/* GENERAPOSICION_HPP */

