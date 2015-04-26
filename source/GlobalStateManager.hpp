
#ifndef GLOBALSTATEMANAGER_HPP
#define	GLOBALSTATEMANAGER_HPP

#include "../engine/GMEngine.hpp"

class GlobalStateManager : public gme::Script{
public:
    GlobalStateManager() : gme::Script() {
        pauseKey = gme::Keyboard::P;
        menuKey = gme::Keyboard::Escape;
        canpause = true;
        gameOver = false;
        player2_exists = false;
    };
    virtual ~GlobalStateManager();
    void pause();
    void resume();
    void setup();
    void update();
    gme::Keyboard::Key pauseKey;
    gme::Keyboard::Key menuKey;

    virtual void onMessage(std::string m, float v);
    
    bool isPaused();

    
private:
    bool paused;
    bool canpause;
    bool gameOver;
    bool player2_exists;
    gme::Clock apretar;

};

#endif	/* GLOBALSTATEMANAGER_HPP */

