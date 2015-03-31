/* 
 * File:   pruebaGameObject.cpp
 * Author: albertomartinezmartinez
 * 
 * Created on 28 de febrero de 2015, 12:20
 */

#include "pruebaGameObject.hpp"
#include "generaPosicion.hpp"
#include "player.hpp"

void pruebaGameObject::setup(){
    
    addTag("player");
    //getRenderer()->setTexture("playerTexture");
 
    generaPosicion *gP = new generaPosicion(300,300,3);
   
    addComponent(gP);
   
    
    
}
