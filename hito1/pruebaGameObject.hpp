#ifndef PRUEBAGAMEOBJECT_HPP
#define	PRUEBAGAMEOBJECT_HPP

#include "../engine/GMEngine.hpp"

class pruebaGameObject : public gme::GameObject {
public:
    pruebaGameObject(std::string n) : gme::GameObject(n){};
    void setup();
private:

};

#endif	/* PRUEBAGAMEOBJECT_HPP */

