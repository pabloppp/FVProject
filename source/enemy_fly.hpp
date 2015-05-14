#ifndef ENEMY_FLY_HPP
#define	ENEMY_FLY_HPP

#include "../engine/GMEngine.hpp"

class enemy_fly : public gme::GameObject {
public:
     enemy_fly(std::string n) : gme::GameObject(n){};
    void setup();
    void update();
private:

};

#endif	/* ENEMY_FLY_HPP */

