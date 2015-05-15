#ifndef MAINGAME_HPP
#define	MAINGAME_HPP

#include "../engine/GMEngine.hpp"

class mainGame : public gme::Game{
public:
    mainGame(gme::Vector2 windowSize, std::string name) : gme::Game(windowSize, name){};
    void setup();
    static bool coop;
    static bool music;
    static bool sound;
    static int particles;
    static bool fullscreen;
    static void saveOpts();
    static void loadOpts();
private:
    

};

#endif	/* MAINGAME_HPP */

