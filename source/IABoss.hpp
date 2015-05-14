#ifndef IABOSS_HPP
#define	IABOSS_HPP

#include "../engine/GMEngine.hpp"
#include "GlobalStateManager.hpp"
#include "LifeManager.hpp"


class IABoss : public gme::Script {
public:
    IABoss() : gme::Script(){
        speed = 4;
        damage = 10;
        walkFPS = 30;
        walkFrameCount =0;
        dead = false;
        dir.x = 1;
        right = true;
        side =false;
        sprint =false;
    };
    void setup();
    void update();
    void animate();
    virtual void onCollision(gme::Collider* c);
    void vectorDirector(gme::Vector2 player, gme::Vector2 enemy);
    virtual void onMessage(std::string m, float v);
    void findPlayer();  
    virtual ~IABoss();
private:
     gme::GameObject *player, *player2;
     GlobalStateManager *stateManager;
     gme::Vector2 dir;
     gme::Clock clk,clkS;
     bool right;
     bool side;
     bool sprint;
     float deltatime;
    void explode(int min, int max, float forcemin, float forcemax);
    float speed;
    float damage;
    bool grounded;
    bool dead;
    LifeManager *lm;
    gme::Clock animClock;
    int walkFPS;
    int walkFrameCount;
    GlobalStateManager *manager;
};

#endif	/* IABOSS_HPP */

