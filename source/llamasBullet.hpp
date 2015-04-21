
#ifndef LLAMASBULLET_HPP
#define	LLAMASBULLET_HPP

#include "../engine/GMEngine.hpp"

class llamasBullet: public gme::GameObject {
public:
    llamasBullet(std::string n): gme::GameObject(n){};
    void setup();
private:

};

#endif	/* LLAMASBULLET_HPP */

