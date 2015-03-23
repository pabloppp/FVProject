
#ifndef WEAPON_HPP
#define	WEAPON_HPP

#include "../engine/GMEngine.hpp"


class weapon : public gme::GameObject{
public:
    weapon(std::string n) : gme::GameObject(n){};
    void setup();
    void change();
    bool overrideKeys;
    gme::Keyboard::Key ShotKey;
    int tipo; //tipo de arma principal
private:
    int ad; //daño de ataque

};

#endif	/* WEAPON_HPP */

