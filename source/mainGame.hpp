#ifndef MAINGAME_HPP
#define	MAINGAME_HPP

#include "../engine/GMEngine.hpp"

class mainGame : public gme::Game{
public:
    mainGame(gme::Vector2 windowSize, std::string name) : gme::Game(windowSize, name){
      
    };
    void setup();
    static bool coop;
    static bool music;
    static bool sound;
    static int particles;
    static bool fullscreen;
    static bool machinegun, shotgun, flamethrower, bazooka, snipper;
    static bool will, marty, drwho;
    static void saveOpts();
    static void loadOpts();
    static void loadProfile();
    static void saveProfile();
    static int continueLevel;
    static int kills, newgames, brokentiles, victories, levelspassed, deaths;
    
    static gme::MusicPlayer *jungleFondo_sound;
private:
    
    
    

};

#endif	/* MAINGAME_HPP */

