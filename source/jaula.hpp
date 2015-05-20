#ifndef JAULA_HPP
#define	JAULA_HPP

#include "../engine/GMEngine.hpp"

class jaula : public gme::GameObject {
public:
    jaula(std::string n) : gme::GameObject(n){};
    virtual void setup();
private:

};

#endif	/* JAULA_HPP */

