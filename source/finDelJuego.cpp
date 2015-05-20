/* 
 * File:   finDelJuego.cpp
 * Author: pablopernias
 * 
 * Created on 20 de mayo de 2015, 11:04
 */

#include "finDelJuego.hpp"
#include "emptyGameObject.hpp"
#include "finDelJuegoScript.hpp"

void finDelJuego::setup() {

    emptyGameObject *eg = new emptyGameObject("finjuego");
    eg->addComponent(new finDelJuegoScript);
}


