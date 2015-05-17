#ifndef PISTOLABEHAVIOR_HPP
#define	PISTOLABEHAVIOR_HPP

#include "../engine/GMEngine.hpp"
#include "GlobalStateManager.hpp"

class pistolaBehavior : public gme::Script  {
public:    
    pistolaBehavior() : gme::Script(){
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
    gme::Clock clock;
    GlobalStateManager *manager;
    
    gme::SoundPlayer *gunShot_sound;
    
};

#endif	/* SHOOTBULLET_HPP */

