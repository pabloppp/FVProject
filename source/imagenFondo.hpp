/* 
 * File:   imagenFondo.hpp
 * Author: Vir
 *
 * Created on 15 de marzo de 2015, 18:14
 */

#ifndef IMAGENFONDO_HPP
#define	IMAGENFONDO_HPP

#include "../engine/GMEngine.hpp"

class imagenFondo: public gme::GameObject {
public:
    imagenFondo(std::string n) : gme::GameObject(n){};
    void setup();
private:

};

#endif	/* IMAGENFONDO_HPP */

