#ifndef PLAYERMOVEMENT_HPP
#define	PLAYERMOVEMENT_HPP

#include "../engine/GMEngine.hpp"
#include "GlobalStateManager.hpp"

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
        
        maxGrenades = 3;
        grenades = maxGrenades;
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
    int points;
    
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
    bool jumped,salto=false;
    float walkingSpeed;
    float jumpForce;
    void animate();
    int walkFPS;
    int sonidoSalto=0;
    int walkFrameCount;
    gme::Clock animClock;
    gme::Clock animGraceTimeClock;
    gme::Clock tlkClock, tlkClock2;
    float animGraceTime;
    bool dead;
    GlobalStateManager *manager;
    
    gme::SoundPlayer *footsteps_sound;
    gme::SoundPlayer *jump_sound;
    gme::SoundPlayer *danyoJugador_sound;
    
    bool grenadeLaunched;
    int grenades;
    int maxGrenades;
    
    
};

#endif	/* PLAYERMOVEMENT_HPP */

