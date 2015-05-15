
#ifndef PISTOLABULLET_HPP
#define	PISTOLABULLET_HPP

#include "../engine/GMEngine.hpp"

class pistolaBullet : public gme::GameObject{
public:
    pistolaBullet(std::string n): gme::GameObject(n){whoshoots=1;};
    void setup();
    int whoshoots;
private:
    
};

#endif	/* BULLET_HPP */

