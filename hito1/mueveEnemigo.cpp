/* 
 * File:   mueveEnemigo.cpp
 * Author: albertomartinezmartinez
 * 
 * Created on 22 de marzo de 2015, 12:16
 */

#include "mueveEnemigo.hpp"

void mueveEnemigo::setup(){
    
}

void mueveEnemigo::update(){
     gme::Vector2 v = em->getTransform()->getPosition();
    v.x--;
    if(v.x < -5){
      
    }
    
    em->getTransform()->setPosition(v);
}

mueveEnemigo::mueveEnemigo(gme::GameObject *g) {
    em = g;
 }


mueveEnemigo::~mueveEnemigo() {
}

