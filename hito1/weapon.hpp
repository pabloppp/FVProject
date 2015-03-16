
#ifndef WEAPON_HPP
#define	WEAPON_HPP

#include "../engine/GMEngine.hpp"


class weapon : public gme::GameObject{
public:
    weapon(std::string n) : gme::GameObject(n){};
    void setup();
    bool overrideKeys;
    gme::Keyboard::Key ShotKey;
    gme::Keyboard::Key keyUp;
    gme::Keyboard::Key keyLeft;
    gme::Keyboard::Key keyRight;
private:
    
};

#endif	/* WEAPON_HPP */

