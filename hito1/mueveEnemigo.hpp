/* 
 * File:   mueveEnemigo.hpp
 * Author: albertomartinezmartinez
 *
 * Created on 22 de marzo de 2015, 12:16
 */

#ifndef MUEVEENEMIGO_HPP
#define	MUEVEENEMIGO_HPP

#include "../engine/GMEngine.hpp"

class mueveEnemigo : public gme::Script {
public:
    void setup();
    void update();
    mueveEnemigo(gme::GameObject *g);
    virtual ~mueveEnemigo();
private:
    gme::GameObject *em;
};

#endif	/* MUEVEENEMIGO_HPP */

