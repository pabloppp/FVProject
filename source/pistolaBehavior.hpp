#ifndef PISTOLABEHAVIOR_HPP
#define	PISTOLABEHAVIOR_HPP

#include "../engine/GMEngine.hpp"

class pistolaBehavior : public gme::Script  {
public:    
    pistolaBehavior() : gme::Script(){
        ShotKey = gme::Keyboard::G;
        keyUp = gme::Keyboard::W;
        keyLeft = gme::Keyboard::A;
        keyRight = gme::Keyboard::D;
        keyDown = gme::Keyboard::S;
    };
    virtual ~pistolaBehavior();
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
    bool shooting;
    int direction; //0 top, 1 dcha, 2 bot, 3 izq 
    int verticalDirection;
    float speedBullet;
    gme::Vector2 winSize;
};

#endif	/* SHOOTBULLET_HPP */

