#ifndef GENERICENEMY_HPP
#define	GENERICENEMY_HPP

#include "../engine/GMEngine.hpp"

class genericEnemy : public gme::GameObject{
public:
    genericEnemy(std::string s) : gme::GameObject(s){};
    virtual void setup();

private:

};

#endif	/* GENERICENEMY_HPP */

