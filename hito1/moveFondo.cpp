/* 
 * File:   fondo.cpp
 * Author: Vir
 * 
 * Created on 15 de marzo de 2015, 13:25
 */

#include "imagenFondo.hpp"
#include "moveFondo.hpp"

void moveFondo::setup(){
    
    gme::Window *w = gme::Game::getWindow();
    vec = w->getSize();
    reloj.restart();
   
}

void moveFondo::update(){
     
    
    if(reloj.currentTime().asSeconds() > 0.01){
        
        getTransform()->translate(gme::Vector2(-x, 0));
        if(getTransform()->position.x <= -320) getTransform()->position.x = 960-x;
        
      reloj.restart();
    
    }

     
}

void moveFondo::onGui() {

}

moveFondo::~moveFondo(){


}
