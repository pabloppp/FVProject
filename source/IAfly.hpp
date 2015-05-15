/* 
 * File:   IAfly.hpp
 * Author: albertomartinezmartinez
 *
 * Created on 12 de mayo de 2015, 18:59
 */

#ifndef IAFLY_HPP
#define	IAFLY_HPP

#include "../engine/GMEngine.hpp"
#include "GlobalStateManager.hpp"

class IAfly : public gme::Script {
public:
    IAfly(bool boss) : gme::Script(){
        dir.x = 1;
        dir.y = 1;
        right =true;
        down = true;
        damage = 3;
        speed = 4;
        rango = 4;
        grounded = false;
        clock =false;
        sprint = false;
        back =  false;
        wait = false;
        change =  false;
        dead = false;
        stop = false;
        enemy_boss = boss;
    };
    void setup();
    void update();
    void vectorDirector(gme::Vector2 player, gme::Vector2 enemy);
    void findPlayer();
    void moveToInit();
    virtual void onGui();
    

    virtual void onMessage(std::string m, float v);

    virtual void onCollision(gme::Collider* c);

private:
    
     void animate();
     void explode(int min, int max, float forcemin, float forcemax);
    std::vector<gme::Vector2> posiciones;
    gme::Vector2 init;
    gme::Vector2 dir; 
    gme::Vector2 gdir;
    float speed;
    float damage;
    bool right;
    bool down;
    float rango;
    bool grounded;
    bool sprint;
    gme::Clock clkG;
    bool clock;
    int pos;
    bool back;
    bool wait;
    bool change;
    bool dead;
    int cornered;
    bool stop;
    int lastXdir;
    int lastYdir;
    bool enemy_boss;
    gme::Clock clkR;
    gme::GameObject *player, *player2;
    GlobalStateManager *stateManager;

};

#endif	/* IAFLY_HPP */

