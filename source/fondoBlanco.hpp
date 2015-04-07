
#ifndef FONDOBLANCO_HPP
#define	FONDOBLANCO_HPP

#include "../engine/GMEngine.hpp"

class fondoBlanco : public gme::GameObject {
public:
    fondoBlanco(std::string n) : gme::GameObject(n){};
    void setup();

private:

};

#endif	/* FONDOBLANCO_HPP */

