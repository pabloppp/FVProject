/* 
 * File:   staticObject.hpp
 * Author: Vir
 *
 * Created on 16 de marzo de 2015, 10:30
 */

#ifndef STATICOBJECT_HPP
#define	STATICOBJECT_HPP

#include "../engine/GMEngine.hpp"

class staticObject: public gme::GameObject {
public:
    staticObject(std::string n) : gme::GameObject(n){};
    void setup();
private:

};

#endif	/* STATICOBJECT_HPP */

