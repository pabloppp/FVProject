
#ifndef METRALLETABEHAVIOR_HPP
#define	METRALLETABEHAVIOR_HPP

#include "../engine/GMEngine.hpp"
#include "Animator.hpp"
#include "GlobalStateManager.hpp"

class metralletaBehavior: public gme::Script  {
public:    
    metralletaBehavior() : gme::Script(){
    };
    virtual ~metralletaBehavior();
    void setup();
    void update();
    virtual void shoot(int d);
    //virtual void onCollision(gme::Collider *c);
    gme::Keyboard::Key ShotKey;
    gme::Keyboard::Key keyUp;
    gme::Keyboard::Key keyLeft;
    gme::Keyboard::Key keyRight;
    gme::Keyboard::Key keyDown;
    int numBullets;
private:
    Animator animator;
    int direction; //0 top, 1 dcha, 2 bot, 3 izq 
    float speedBullet;
    float cadency = 0.1f;
    int directionSp;
    int verticalDirection;
    gme::Clock clock;
    gme::Clock tlkClock;
    bool recargando;
    GlobalStateManager *manager;
    
    gme::MusicPlayer *metralletaShot_sound;
    gme::MusicPlayer *metralletaReload_sound;
};

#endif	/* METRALLETABEHAVIOR_HPP */

