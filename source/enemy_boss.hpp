#ifndef ENEMY_BOSS_HPP
#define	ENEMY_BOSS_HPP

#include "../engine/GMEngine.hpp"

class enemy_boss : public gme::GameObject {
public:
    enemy_boss(std::string n) : gme::GameObject(n){};
    void setup();
    void update();
private:

};

#endif	/* ENEMY_BOSS_HPP */

