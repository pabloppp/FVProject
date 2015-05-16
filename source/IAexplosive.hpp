#ifndef IAEXPLOSIVE_HPP
#define	IAEXPLOSIVE_HPP

#include "../engine/GMEngine.hpp"
#include "GlobalStateManager.hpp"

class IAexplosive : public gme::Script {
public:
    IAexplosive() :gme::Script(){
        damage   = 3;
        dir.x    = 1;
        right    = true;
        speed    = 5;
        wait     = false;
        sprint   = false;
        grounded = false;
        acted    = false;
        fixPos   = true;
        boomb    = false;
        dead     = false;
    };
    void setup();
    void update();
    void findPlayer();
    void vectorDirector(gme::Vector2 player, gme::Vector2 enemy);
     void jump(gme::Vector2 player, gme::Vector2 enemy);

    virtual void onCollision(gme::Collider* c);

    virtual void onMessage(std::string m, float v);


private:
    void explode(int min, int max, float forcemin, float forcemax) ;
    gme::GameObject *player,*player2;
    gme::Vector2 dir;
    gme::Vector2 spawn;
    bool fixPos;
    bool right;
    float damage;
    float timepas;
    float speed;
    bool wait;
    bool sprint;
    bool acted;
    float deltatime;
    bool grounded;
    int cornered;
    gme::Clock clk;
    gme::Clock clkJ;
    gme::Clock clkW;
    gme::Clock clkB;
    bool boomb;
    bool dead;
     GlobalStateManager *stateManager;
};

#endif	/* IAEXPLOSIVE_HPP */

