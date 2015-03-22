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
    moveFondo() : gme::Script(){
     upKey = gme::Keyboard::Up;
     downKey = gme::Keyboard::Down;
     introKey = gme::Keyboard::Return;
     spaceKey = gme::Keyboard::Space;
     bacKey = gme::Keyboard::BackSpace;
     pauseKey = gme::Keyboard::P;
        
    };
    void setup();
    void update();
    virtual void onGui();
    virtual ~moveFondo();
    
    gme::Keyboard::Key upKey;
    gme::Keyboard::Key downKey;
    gme::Keyboard::Key introKey;
    gme::Keyboard::Key spaceKey;
    gme::Keyboard::Key bacKey;
    gme::Keyboard::Key pauseKey;
    
private:
    
    gme::Window *w;
    gme::Clock reloj;
    int x=1, largo=280, ancho=30,num_apre,num_apre_ini,menu, posX,pausa_visible;
    gme::Vector2 vec;
    gme::Clock apretar;
    bool sonando,izq,dre,pausa,apretado,music_pausa;
    gme::MusicPlayer *musica;
    gme::MusicPlayer *musicabtn;
    gme::MusicPlayer *musicadesp;


};

#endif	/* FONDO_HPP */

