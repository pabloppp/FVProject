/* 
 * File:   pruebaGameObject.cpp
 * Author: albertomartinezmartinez
 * 
 * Created on 28 de febrero de 2015, 12:20
 */

#include "pruebaGameObject.hpp"
#include "generaPosicion.hpp"

void pruebaGameObject::setup(){
    addTag("player");
    getRenderer()->setTexture("prueba");
    
    generaPosicion *gP = new generaPosicion();
    addComponent(gP);
    //addComponent(new gme::RigidBody);
}
