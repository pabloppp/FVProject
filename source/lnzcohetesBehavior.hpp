#ifndef LNZCOHETESBEHAVIOR_HPP
#define	LNZCOHETESBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"

class lnzcohetesBehavior: public gme::Script {
public:
    lnzcohetesBehavior(): gme::Script(){
        ShotKey = gme::Keyboard::G;
        keyUp = gme::Keyboard::W;
        keyLeft = gme::Keyboard::A;
        keyRight = gme::Keyboard::D;
        keyDown = gme::Keyboard::S;
    };
    void setup();
    void update();
    void shoot(int d);
    virtual ~lnzcohetesBehavior();
    gme::Keyboard::Key ShotKey;
    gme::Keyboard::Key keyUp;
    gme::Keyboard::Key keyLeft;
    gme::Keyboard::Key keyRight;
    gme::Keyboard::Key keyDown;
private:
    gme::Vector2 winSize;
    float speedBullet;
    bool shooting;
    int direction;
    gme::Clock clock;
};

#endif	/* LNZCOHETESBEHAVIOR_HPP */

