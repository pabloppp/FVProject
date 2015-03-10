#ifndef ASTEROID_HPP
#define	ASTEROID_HPP

#include "../engine/GMEngine.hpp"

class Asteroid : public gme::GameObject{
public:
    Asteroid(std::string n) : gme::GameObject(n){};
    void setup();
private:

};

#endif	/* ASTEROID_HPP */

