#ifndef LNZLLAMASBEHAVIOR_HPP
#define	LNZLLAMASBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"
#include "Animator.hpp"

class lnzllamasBehavior : public gme::Script {
public:
    lnzllamasBehavior() : gme::Script(){
        ShotKey = gme::Keyboard::G;
        keyUp = gme::Keyboard::W;
        keyLeft = gme::Keyboard::A;
        keyRight = gme::Keyboard::D;
        keyDown = gme::Keyboard::S;
    };
    virtual ~lnzllamasBehavior();
    void setup();
    void update();
    virtual void shoot(int d);
    gme::Keyboard::Key ShotKey;
    gme::Keyboard::Key keyUp;
    gme::Keyboard::Key keyLeft;
    gme::Keyboard::Key keyRight;
    gme::Keyboard::Key keyDown;
private:
    Animator animator;
    int directionSp;
    int direction; //0 top, 1 dcha, 2 bot, 3 izq 
    float speedBullet;
    float cadency = 0.1f;
    gme::Vector2 winSize;
};

#endif	/* LNZLLAMASBEHAVIOR_HPP */

