
#ifndef VOIDOBJECT_HPP
#define	VOIDOBJECT_HPP

#include "../engine/GMEngine.hpp"

class voidObject : public gme::GameObject{
public:
    voidObject(std::string n) : gme::GameObject(n){};
    void setup();
    void update();
private:

};

#endif	/* VOIDOBJECT_HPP */

