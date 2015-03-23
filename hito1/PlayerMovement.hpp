#ifndef PLAYERMOVEMENT_HPP
#define	PLAYERMOVEMENT_HPP

#include "../engine/GMEngine.hpp"

class PlayerMovement : public gme::Script{
public:
    PlayerMovement() : gme::Script(){
        walkingSpeed = 3 * 100;
        jumpForce = 40 * 1000;
        walkFPS = 20;
        
        upKey = gme::Keyboard::W;
        downKey = gme::Keyboard::S;
        leftKey = gme::Keyboard::A;
        rightKey = gme::Keyboard::D;
        jumpKey = gme::Keyboard::F;
        weaponKey = gme::Keyboard::G;
        actionKey = gme::Keyboard::H;
        changeWeapon = gme::Keyboard::X;
    };
    void setup();
    void update();   
    virtual void onCollision(gme::Collider *c);
    virtual ~PlayerMovement();
    int state; //0: idle, 1: walking
    bool grounded;
    bool hitWallRight;
    bool hitWallLeft;
    bool flipped;
    
    gme::Keyboard::Key upKey;
    gme::Keyboard::Key downKey;
    gme::Keyboard::Key leftKey;
    gme::Keyboard::Key rightKey;
    gme::Keyboard::Key jumpKey;
    gme::Keyboard::Key weaponKey;
    gme::Keyboard::Key actionKey;
    gme::Keyboard::Key changeWeapon;
private:
    bool jumped;
    float walkingSpeed;
    float jumpForce;
    void animate();
    int walkFPS;
    int walkFrameCount;
    gme::Clock animClock;
};

#endif	/* PLAYERMOVEMENT_HPP */

