#ifndef LIFEMANAGER_HPP
#define	LIFEMANAGER_HPP

#include "../engine/GMEngine.hpp"

class LifeManager : public gme::Script{
public:
    LifeManager() : gme::Script(){
        maxHp = 100;
        hp = maxHp;
        maxLives = 3;
        lives = maxLives;
        waitTime = 0.5; //segundos
        showDamage = false;
        startShowDamage = false;
    };
    void setup();
    void update();
    int getHp();
    int getLives();
    int getMaxHp();
    int getMaxLives();
    float getHpPercent();
    virtual void onMessage(std::string m, float v);
    int maxHp;
    int maxLives;
    float waitTime;
    gme::Clock waitClock;
    bool showDamage, startShowDamage;
    int r, g, b;

private:
    int hp;
    int lives;
    
};

#endif	/* LIFEMANAGER_HPP */

