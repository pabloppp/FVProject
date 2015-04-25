#ifndef DEFAULTPARTICLE_HPP
#define	DEFAULTPARTICLE_HPP

#include "../engine/GMEngine.hpp"

class defaultParticle : public gme::GameObject {
public:
    defaultParticle(std::string n) : gme::GameObject(n){};
    virtual void setup();
    gme::Vector2 startingPosition;
private:

};

#endif	/* DEFAULTPARTICLE_HPP */

