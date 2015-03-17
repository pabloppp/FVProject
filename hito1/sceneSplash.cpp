/* 
 * File:   sceneSplash.cpp
 * Author: Vir
 * 
 * Created on 16 de marzo de 2015, 11:14
 */

#include "sceneSplash.hpp"
#include "staticObject.hpp"

void sceneSplash::setup(){
   
    /*//sp->autoplay = true;
    musica->setVolume(0);
    musica->loop(true);
   // addComponent(sp);
    */
   gme::GameObject *fondo= new staticObject("fondo");
   fondo->getTransform()->setPosition(gme::Vector2(320, 240));
   fondo->getRenderer()->setTexture("fondoSplash");
   fondo->getRenderer()->setColor(255,255,255,0);
    
}
