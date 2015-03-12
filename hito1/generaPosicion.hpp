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
    void position(int x, int y,int rat, std::string tipo,int state);
    void setState(int i);
    int getState();
    virtual void onGui();
    virtual ~generaPosicion();
private:
    gme::Vector2 v;
    double angle;
    gme::Clock clk;
    sf::CircleShape ratio;
    gme::Window *w;
    std::string tipoObjeto;
    int stateObjeto;
};

#endif	/* GENERAPOSICION_HPP */

