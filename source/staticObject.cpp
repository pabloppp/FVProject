/* 
 * File:   staticObject.cpp
 * Author: Vir
 * 
 * Created on 16 de marzo de 2015, 10:30
 */

#include "staticObject.hpp"
#include "splash.hpp"

void staticObject::setup(){
    
   // std::cout <<hito1Game::getCurrentScene()->getName() << std::endl;

    if(gme::Game::getCurrentScene()->getName()=="splash"){
        splash *accionSplash = new splash();
        addComponent(accionSplash);
    //getRenderer()->setSize(gme::Vector2(640,480));
    }

}

