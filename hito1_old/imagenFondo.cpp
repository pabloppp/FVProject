/* 
 * File:   imagenFondo.cpp
 * Author: Vir
 * 
 * Created on 15 de marzo de 2015, 18:14
 */

#include "imagenFondo.hpp"
#include "moveFondo.hpp"

void imagenFondo::setup(){
    
    getRenderer()->setSize(gme::Vector2(640,480));
    
    moveFondo *accion = new moveFondo();
    addComponent(accion);
}

