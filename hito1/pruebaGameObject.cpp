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
 
    generaPosicion *gP = new generaPosicion();
    gP->position(620,30,80,"coleccionable",0);
    gP->setState(1);
    addComponent(gP);
   
    
    
}
