
#ifndef COLECTABLEGAMEOBJECT_HPP
#define	COLECTABLEGAMEOBJECT_HPP


#include "../engine/GMEngine.hpp"

class colectableGameObject : public gme::GameObject {
public:
    colectableGameObject(std::string n) : gme::GameObject(n){};
    void setup();
private:

};

#endif	/* COLECTABLEGAMEOBJECT_HPP */

