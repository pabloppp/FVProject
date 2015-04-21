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
    generaPosicion(int x,int y,int ratio);
    void setup();
    void update();
    bool getColectionable();
    void setColectionable(bool x);
    bool getEnemi();
    void setEnemi(bool x);
    virtual void onGui();
    void generaColeccionable();
    void generaEnemigo(int x, int y);
    void addPosition(int x, int y);
    
private:
    gme::Vector2 v;
    gme::Window *w;
    bool colectionable;
    bool enemi;
    gme::Clock clkC;
    gme::Clock clkE;
    int posX;
    int posY;
    int rat;
    std::vector<gme::Vector2> posiciones;
};

#endif	/* GENERAPOSICION_HPP */
