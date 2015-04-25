
#ifndef WEAPON_HPP
#define	WEAPON_HPP

#include "../engine/GMEngine.hpp"


class weapon : public gme::GameObject{
public:
    weapon(std::string n) : gme::GameObject(n){};
    void setup();
    
    
private: 

};

#endif	/* WEAPON_HPP */

