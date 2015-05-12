#ifndef LNZLLAMASBEHAVIOR_HPP
#define	LNZLLAMASBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"
#include "Animator.hpp"
#include "GlobalStateManager.hpp"

class lnzllamasBehavior : public gme::Script {
public:
    lnzllamasBehavior() : gme::Script(){
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
    int numBullets;
private:
    Animator animator;
    int directionSp;
    int direction; //0 top, 1 dcha, 2 bot, 3 izq 
    float speedBullet;
    float cadency = 3.1f;
    gme::Vector2 winSize;
    int verticalDirection;
    bool recargando;
    gme::Clock clock;
    GlobalStateManager *manager;
};

#endif	/* LNZLLAMASBEHAVIOR_HPP */

