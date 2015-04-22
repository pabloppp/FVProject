
#ifndef PISTOLABULLET_HPP
#define	PISTOLABULLET_HPP

#include "../engine/GMEngine.hpp"

class pistolaBullet : public gme::GameObject{
public:
    pistolaBullet(std::string n): gme::GameObject(n){};
    void setup();
private:
    
};

#endif	/* BULLET_HPP */

