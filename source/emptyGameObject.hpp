#ifndef EMPTYGAMEOBJECT_HPP
#define	EMPTYGAMEOBJECT_HPP

#include "../engine/GMEngine.hpp"

class emptyGameObject : public gme::GameObject {
public:
    emptyGameObject(std::string n) : gme::GameObject(n){};
    virtual void setup();
private:

};

#endif	/* EMPTYGAMEOBJECT_HPP */

