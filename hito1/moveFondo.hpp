/* 
 * File:   fondo.hpp
 * Author: Vir
 *
 * Created on 15 de marzo de 2015, 13:25
 */

#ifndef FONDO_HPP
#define	FONDO_HPP


#include "../engine/GMEngine.hpp"

class moveFondo : public gme::Script {
public:
    void setup();
    void update();
    virtual void onGui();
    virtual ~moveFondo();
private:
       
    gme::Clock reloj;
    int x=1;
    gme::Vector2 vec;

};

#endif	/* FONDO_HPP */

