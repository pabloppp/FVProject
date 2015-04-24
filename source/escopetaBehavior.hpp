
#ifndef ESCOPETABEHAVIOR_HPP
#define	ESCOPETABEHAVIOR_HPP
 
#include "../engine/GMEngine.hpp"
#include "Animator.hpp"
 
class escopetaBehavior: public gme::Script {
public:
    escopetaBehavior() : gme::Script(){
    };
    gme::Keyboard::Key ShotKey;
    gme::Keyboard::Key keyUp;
    gme::Keyboard::Key keyLeft;
    gme::Keyboard::Key keyRight;
    gme::Keyboard::Key keyDown;
    virtual ~escopetaBehavior();
    void setup();
    void update();
    void shoot(int d);
private:
    float speedBullet;
    bool shooting;
    int direction;
    int verticalDirection;
    gme::Clock clock;
};

#endif	/* ESCOPETABEHAVIOR_HPP */

