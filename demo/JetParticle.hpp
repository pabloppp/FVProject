#ifndef JETPARTICLE_HPP
#define	JETPARTICLE_HPP

#include "../engine/GMEngine.hpp"

class JetParticle : public gme::GameObject{
public:
    JetParticle(std::string n) : gme::GameObject(n){};
    void setup();
private:

};

#endif	/* JETPARTICLE_HPP */

