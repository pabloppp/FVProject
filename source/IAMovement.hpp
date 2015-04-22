/* 
 * File:   IAMovement.hpp
 * Author: albertomartinezmartinez
 *
 * Created on 14 de abril de 2015, 18:18
 */

#ifndef IAMOVEMENT_HPP
#define	IAMOVEMENT_HPP

#include "../engine/GMEngine.hpp"

class IAMovement : public gme::Script {
public:
    IAMovement() : gme::Script(){
        walkFPS = 30;
        walkFrameCount = 0;
    };
    void setup();
    void update();
    void findPlayer();   
    void jump(gme::Vector2 player, gme::Vector2 enemy);
    void vectorDirector(gme::Vector2 player, gme::Vector2 enemy);
    virtual ~IAMovement();

    virtual void onMessage(std::string m, float v);


    virtual void onCollision(gme::Collider* c);

private:
    gme::GameObject *player;
    gme::Clock clk,clkJ,clkPJ;
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
    bool dead, destroyed;
    gme::GameObject *trigger;
    
    gme::Vector2 spawn;
    
    gme::Clock animClock;
    
};

#endif	/* IAMOVEMENT_HPP */

