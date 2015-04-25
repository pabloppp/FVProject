
#ifndef ENEMYFAST_HPP
#define	ENEMYFAST_HPP

#include "../engine/GMEngine.hpp"


class enemy_fast : public gme::GameObject {
public:
    enemy_fast(std::string n) : gme::GameObject(n){};
    void setup();
    void update();
private:
};

#endif	/* ENEMYFAST_HPP */

