/* 
 * File:   staticObject.cpp
 * Author: Vir
 * 
 * Created on 16 de marzo de 2015, 10:30
 */

#include "staticObject.hpp"
#include "splash.hpp"
#include "hito1Game.hpp"

void staticObject::setup(){
    
   // std::cout <<hito1Game::getCurrentScene()->getName() << std::endl;

    if(hito1Game::getCurrentScene()->getName()=="sceneS"){
        splash *accionSplash = new splash();
        addComponent(accionSplash);
    //getRenderer()->setSize(gme::Vector2(640,480));
    }

}

