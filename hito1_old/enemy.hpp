
#ifndef ENEMY_HPP
#define	ENEMY_HPP

#include "../engine/GMEngine.hpp"


class enemy : public gme::GameObject {
public:
    enemy(std::string n) : gme::GameObject(n){};
    void setup();
    void update();
    void setSpeed(int sp);
    int getSpeed();
    void setDamage(int dam);
    int getDamage();
private:
    int speed;
    int damage;
};

#endif	/* ENEMY_HPP */

