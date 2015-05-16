/* 
 * File:   IAfly.hpp
 * Author: albertomartinezmartinez
 *
 * Created on 15 de mayo de 2015, 14:58
 */

#ifndef IAFLY_HPP
#define	IAFLY_HPP

#include "../engine/GMEngine.hpp"
#include "GlobalStateManager.hpp"

class IAfly : public gme::Script {
public:
    IAfly(bool boss) : gme::Script(){
        enemy_boss= boss;
        if(!enemy_boss){
            damage = 5;
            speed = 6;
        }
        else{
            damage = 15;
            speed = 6;
        }
        first = true;
        down = true;
        grounded = false;
        side =false;
        dir.y = 1;
        corner = false;
        boing = false;
        Vboing= false;
        randmove = false;
        sprint = false;
        home = false;
        wait = false;
        dead = false;
        
        chase = true;
        wave = false;
        fallDown =false;
    };
    
    void setup();
    void update();
    
    void findPlayer();
    
    void vectorDirector(gme::Vector2 player, gme::Vector2 enemy);
    void moveToInit();
    void bossAttack();
    void waveAttack(gme::Vector2 player, gme::Vector2 enemy);
    void fallDownAttack(gme::Vector2 player, gme::Vector2 enemy);
    

    virtual void onCollision(gme::Collider* c);
    virtual void onMessage(std::string m, float v);
    virtual void onGui();
 
private:
    
    float damage;
    float speed;
    
    
    bool enemy_boss;
    bool right;
    bool down;
    bool first;
    bool grounded;
    bool side;
    bool corner;
    bool boing;
    bool Vboing;
    bool move;
    bool randmove;
    bool sprint;
    bool home;
    bool wait;
    bool dead;
    bool chase;
    bool wave;
    bool fallDown;
    
    gme::Vector2 dir;
    gme::Vector2 gdir;
    gme::Vector2 init;
    
    gme::Clock clkW;
    gme::Clock clkCA;
    
    std::vector<gme::Vector2> positions;
    std::vector<gme::Vector2> wavePositions;
    
    gme::GameObject *player,*player2;
    GlobalStateManager *stateManager;
    
    void explode(int min, int max, float forcemin, float forcemax);
};

#endif	/* IAFLY_HPP */

