/* 
 * File:   IAMovement.hpp
 * Author: albertomartinezmartinez
 *
 * Created on 14 de abril de 2015, 18:18
 */

#ifndef IAMOVEMENT_HPP
#define	IAMOVEMENT_HPP

#include "../engine/GMEngine.hpp"
#include "GlobalStateManager.hpp"

class IAMovement : public gme::Script {
public:
    IAMovement() : gme::Script(){
        walkFPS = 30;
        walkFrameCount = 0;
        speed = 7;
        damage = 5;
    };
    void setup();
    void update();
    void findPlayer();   
    void jump(gme::Vector2 player, gme::Vector2 enemy);
    void vectorDirector(gme::Vector2 player, gme::Vector2 enemy);
    virtual ~IAMovement();
    virtual void onMessage(std::string m, float v);
    virtual void onCollision(gme::Collider* c);
    virtual void onGui();
    float speed;
    float damage;

private:
    gme::GameObject *player, *player2;
    gme::Clock clk,clkJ,clkPJ,clksound;
    gme::Vector2 dir = gme::Vector2(1,0);
    bool right,left, jumping;
    float timepas;
    int check;
    float deltatime,elapsetime;
    bool grounded;
    void animate();
    int walkFrameCount;
    int walkFPS;
    int cornered;
    bool acted;
    gme::SoundPlayer *danyoEnemigo_sound;
    
    GlobalStateManager *stateManager;
    
    
    
    bool dead, destroyed;
    
    gme::Vector2 spawn;
    
    gme::Clock animClock;
    
    void explode(int min, int max, float forcemin, float forcemax);
    
    bool fixPos;
    
    
};

#endif	/* IAMOVEMENT_HPP */

