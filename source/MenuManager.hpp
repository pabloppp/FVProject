
#ifndef MENUMANAGER_HPP
#define	MENUMANAGER_HPP

#include "../engine/GMEngine.hpp"

class MenuManager : public gme::Script{
public:
    MenuManager() : gme::Script() {
        upKey = gme::Keyboard::Up;
        downKey = gme::Keyboard::Down;
        introKey = gme::Keyboard::Return;
        bacKey = gme::Keyboard::BackSpace;
        resumeKey = gme::Keyboard::R;
    };
    virtual ~MenuManager();
    void setup();
    void update();
    void openMenu();
    void openPause();
    virtual void onGui();
    virtual void onMessage(std::string m, float v);
    gme::Keyboard::Key upKey;
    gme::Keyboard::Key downKey;
    gme::Keyboard::Key introKey;
    gme::Keyboard::Key bacKey;
    gme::Keyboard::Key resumeKey;
private:
    gme::Window *w;
    gme::MusicPlayer *music;
    gme::MusicPlayer *button_sound;
    gme::MusicPlayer *change_sound;
    bool sonando, izq, dre, apretado, music_pausa;
    int x=1, largo=280, ancho=30, num_apre, num_apre_ini, menu, posX, pausa_visible;
    bool pausa, menudejuego, juegoNuevo1p, juegoNuevo2p;
    gme::Clock reloj_fondo;
    gme::Clock apretar;

};

#endif	/* MENUMANAGER_HPP */

