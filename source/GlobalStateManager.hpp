
#ifndef GLOBALSTATEMANAGER_HPP
#define	GLOBALSTATEMANAGER_HPP

#include "../engine/GMEngine.hpp"
#include "Animator.hpp"

class GlobalStateManager : public gme::Script{
public:
    GlobalStateManager() : gme::Script() {
        pauseKey = gme::Keyboard::P;
        escKey = gme::Keyboard::Escape;
        canpause = true;
        gameOver = false;
        player2_exists = false;
        gameType = 1; // 1 Por tiempo 2 Por puntuacion 3 Kill them all 4 Boss
        winCondition = 60;
        lastScore = 0;
        levelSuccess = false;
        goToMenu = false;
        gameClock.restart();
        startready = false;
        nextScene = "";
    };
    virtual ~GlobalStateManager();
    void pause();
    void resume();
    void setup();
    void update();
    void isGameOver();
    void spawnP2();
    gme::Keyboard::Key pauseKey;
    gme::Keyboard::Key escKey;

    virtual void onMessage(std::string m, float v);
    bool isPaused();
    int gameType;
    float winCondition;
    float lastScore;
    gme::Clock gameClock;
    std::string nextScene;
    static int pointsp1, pointsp2, maxpoints;
    Animator anim;
    
private:
    bool paused;
    bool goToMenu;
    bool canpause;
    bool gameOver;
    bool player2_exists;
    bool levelSuccess;
    bool startready;   
    gme::SoundPlayer *ready_player;
    gme::Clock apretar;
    
};

#endif	/* GLOBALSTATEMANAGER_HPP */

