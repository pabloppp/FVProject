
#ifndef COLECTABLEGAMEOBJECT_HPP
#define	COLECTABLEGAMEOBJECT_HPP


#include "../engine/GMEngine.hpp"

class colectableGameObject : public gme::GameObject {
public:
    colectableGameObject(std::string n, int i) : gme::GameObject(n){
     objectType = i;
    };
    void setup();
private:
    int objectType;

};

#endif	/* COLECTABLEGAMEOBJECT_HPP */

