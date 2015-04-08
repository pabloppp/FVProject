
#ifndef METRALLETABEHAVIOR_HPP
#define	METRALLETABEHAVIOR_HPP

#include "../engine/GMEngine.hpp"
#include "Animator.hpp"

class metralletaBehavior: public gme::Script  {
public:    
    metralletaBehavior() : gme::Script(){
        ShotKey = gme::Keyboard::G;
        keyUp = gme::Keyboard::W;
        keyLeft = gme::Keyboard::A;
        keyRight = gme::Keyboard::D;
        keyDown = gme::Keyboard::S;
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
private:
    Animator animator;
    int direction; //0 top, 1 dcha, 2 bot, 3 izq 
    float speedBullet;
    float cadency = 0.1f;
    int directionSp;
    
};

#endif	/* METRALLETABEHAVIOR_HPP */

