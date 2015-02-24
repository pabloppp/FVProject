#ifndef FIRSTGAMEOBJECT_HPP
#define	FIRSTGAMEOBJECT_HPP

#include "../engine/GMEngine.hpp"


class Starship : public gme::GameObject{
public:
    Starship(std::string n) : gme::GameObject(n){};
    void setup();
private:

};

#endif	/* FIRSTGAMEOBJECT_HPP */

