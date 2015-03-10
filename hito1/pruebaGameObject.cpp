/* 
 * File:   pruebaGameObject.cpp
 * Author: albertomartinezmartinez
 * 
 * Created on 28 de febrero de 2015, 12:20
 */

#include "pruebaGameObject.hpp"
#include "generaPosicion.hpp"
#include "../demo/CustomScript.hpp"

void pruebaGameObject::setup(){
    
    addTag("player");
    getRenderer()->setTexture("prueba");
    
    //addComponent(new CustomScript());
    //addComponent(new gme::RigidBody);
    
    generaPosicion *gP = new generaPosicion();
    gP->position(320,90,80);
    addComponent(gP);
   
    
    
}
