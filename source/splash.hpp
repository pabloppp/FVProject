/* 
 * File:   splash.hpp
 * Author: Vir
 *
 * Created on 16 de marzo de 2015, 11:25
 */

#ifndef SPLASH_HPP
#define	SPLASH_HPP

#include "../engine/GMEngine.hpp"

class splash : public gme::Script {
public:
    splash() : gme::Script(){
        spaceKey = gme::Keyboard::Space;
    }
    void setup();
    void update();
    virtual ~splash();
    gme::Keyboard::Key spaceKey;
private:
       
    gme::Clock reloj;
    gme::Clock trans;
    float a=0;
    gme::Vector2 vec;

};

#endif	/* SPLASH_HPP */

