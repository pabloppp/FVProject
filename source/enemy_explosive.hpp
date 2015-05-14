
#ifndef ENEMY_EXPLOSIVE_HPP
#define	ENEMY_EXPLOSIVE_HPP

#include "../engine/GMEngine.hpp"


class enemy_explosive : public gme::GameObject{
public:
    enemy_explosive(std::string n) : gme::GameObject(n){};
    void setup();
    void update();
private:

};

#endif	/* ENEMY_EXPLOSIVE_HPP */

