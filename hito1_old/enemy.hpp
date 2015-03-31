
#ifndef ENEMY_HPP
#define	ENEMY_HPP

#include "../engine/GMEngine.hpp"


class enemy : public gme::GameObject {
public:
    enemy(std::string n) : gme::GameObject(n){};
    void setup();
    void update();
    int life;
private:
    
};

#endif	/* ENEMY_HPP */

