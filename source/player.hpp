#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include "../engine/GMEngine.hpp"

class player : public gme::GameObject{
public:
    player(std::string n) : gme::GameObject(n){};
    void setup();
    bool overrideKeys;
    gme::Keyboard::Key upKey;
    gme::Keyboard::Key downKey;
    gme::Keyboard::Key leftKey;
    gme::Keyboard::Key rightKey;
    gme::Keyboard::Key jumpKey;
    gme::Keyboard::Key weaponKey;
    gme::Keyboard::Key actionKey;
    gme::Keyboard::Key changeWeapon;
private:

};

#endif	/* PLAYER_HPP */

