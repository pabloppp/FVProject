/* 
 * File:   splash.cpp
 * Author: Vir
 * 
 * Created on 16 de marzo de 2015, 11:25
 */

#include "splash.hpp"
#include "staticObject.hpp"
#include "hito1Game.hpp"

void splash::setup(){
    
    gme::Window *w = gme::Game::getWindow();
    vec = w->getSize();
    reloj.restart();
    
   
}

void splash::update(){
    
    //std::cout <<reloj.currentTime().asSeconds() << std::endl;

    
    
    
    if(trans.currentTime().asSeconds()>(0.01) && reloj.currentTime().asSeconds()<=3 && a>=0){
        
                getRenderer()->setColor(255,255,255,a);
                a+=2.8;
                /*std::cout <<a<< std::endl;
                if(a>=255){
                    
                    reloj.restart();
                }*/
               trans.restart();
        }
    
    if(trans.currentTime().asSeconds()>(0.01) && reloj.currentTime().asSeconds()>=5 && a>0){
        
                getRenderer()->setColor(255,255,255,a);
                a-=2.8;
                /*std::cout <<a<< std::endl;
                if(a>=255){
                    
                    reloj.restart();
                }*/
               trans.restart();
        }
    
    if(reloj.currentTime().asSeconds()>8) getRenderer()->setColor(0,0,0,0);
    
    if(reloj.currentTime().asSeconds() > 9){

      hito1Game::setCurrentScene("sceneM");
        
      reloj.restart();
    
   }

     
}
    


splash::~splash(){


}

