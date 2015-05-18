#ifndef ENEMY_FINAL_HPP
#define	ENEMY_FINAL_HPP

#include "../engine/GMEngine.hpp"

class enemy_Final : public gme::GameObject {
public:
    enemy_Final(std::string n) : gme::GameObject(n){};
    void setup();
private:

};

#endif	/* ENEMY_FINAL_HPP */

