/* 
 * File:   generaPosicion.hpp
 * Author: albertomartinezmartinez
 *
 * Created on 28 de febrero de 2015, 12:38
 */

#ifndef GENERAPOSICION_HPP
#define	GENERAPOSICION_HPP

#include "../engine/GMEngine.hpp"
#include "GlobalStateManager.hpp"

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

    virtual void onMessage(std::string m, float v);
    void setCollectableLimits(int xmin, int xmax);
    int ene1, ene2, ene3, ene4; //embestidor, rapido, volador, explosivo
    
private:
    gme::Vector2 v;
    gme::Window *w;
    bool colectionable;
    bool enemi;
    bool destroyed;
    gme::Clock clkC;
    gme::Clock clkE;
    int posX;
    int posY;
    int rat;
    std::vector<gme::Vector2> posiciones;
    int objects;
    int randomtime;
    int lObjectType;
    int colMinX;
    GlobalStateManager *manager;
};

#endif	/* GENERAPOSICION_HPP */

