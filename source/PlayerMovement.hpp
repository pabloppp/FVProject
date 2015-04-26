#ifndef PLAYERMOVEMENT_HPP
#define	PLAYERMOVEMENT_HPP

#include "../engine/GMEngine.hpp"

class PlayerMovement : public gme::Script{
public:
    PlayerMovement() : gme::Script(){
        walkingSpeed = 3 * 100;
        jumpForce = 40 * 1000;
        walkFPS = 20;
        
        upKey = gme::Keyboard::Up;
        downKey = gme::Keyboard::Down;
        leftKey = gme::Keyboard::Left;
        rightKey = gme::Keyboard::Right;
        jumpKey = gme::Keyboard::Space;
        weaponKey = gme::Keyboard::X;
        actionKey = gme::Keyboard::Z;
        
        animGraceTime = 0.01;
        changeWeapon = gme::Keyboard::Q;
    };
    void setup();
    void update();   
    virtual void onCollision(gme::Collider *c);
    virtual void onGui();
    virtual ~PlayerMovement();

    virtual void onMessage(std::string m, float v);

    int state; //0: idle, 1: walking
    bool grounded;
    bool down; //agachado
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
    gme::BoxCollider *agachadoCollider;
    gme::Keyboard::Key changeWeapon;
private:
    bool jumped;
    float walkingSpeed;
    float jumpForce;
    void animate();
    int walkFPS;
    int walkFrameCount;
    gme::Clock animClock;
    gme::Clock animGraceTimeClock;
    float animGraceTime;
    bool dead;
    
};

#endif	/* PLAYERMOVEMENT_HPP */

