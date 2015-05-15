#ifndef ENEMY_FLY_HPP
#define	ENEMY_FLY_HPP

#include "../engine/GMEngine.hpp"

class enemy_fly : public gme::GameObject {
public:
     enemy_fly(std::string n, bool boss) : gme::GameObject(n){
         enemy_boss = boss;
     };
    void setup();
    void update();
private:
    bool enemy_boss;
};

#endif	/* ENEMY_FLY_HPP */

