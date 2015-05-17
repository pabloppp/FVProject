#ifndef MAINMENUSETUP_HPP
#define	MAINMENUSETUP_HPP

#include "../engine/GMEngine.hpp"
class MainMenuSetup: public gme::Script {
public:
    MainMenuSetup() : gme::Script(){
        upKey = gme::Keyboard::Up;
        downKey = gme::Keyboard::Down;
        introKey = gme::Keyboard::Return;
        bacKey = gme::Keyboard::BackSpace;
    };
    virtual ~MainMenuSetup();
    void setup();
    void update();
    void onGui();
    void movement();
    gme::Keyboard::Key upKey;
    gme::Keyboard::Key downKey;
    gme::Keyboard::Key introKey;
    gme::Keyboard::Key bacKey;
private:
    gme::Window *w;
    int menu, posX, num_apre_ini, num_apre;
    int x=1, largo=310, ancho=40;
    bool izq, dre, juegoNuevo1p, juegoNuevo2p, entered;    
    gme::Clock reloj_fondo;
    gme::Clock apretar;
    gme::SoundPlayer *button_sound;
   // gme::MusicPlayer *music_jungle;
};

#endif	/* MAINMENUSETUP_HPP */

