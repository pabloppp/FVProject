#include "splash.hpp"
#include "staticObject.hpp"
#include "mainGame.hpp"

void splash::setup(){
    
    gme::Window *w = gme::Game::getWindow();
    vec = w->getSize();
    reloj.restart();
}

void splash::update(){
    if(trans.currentTime().asSeconds()>(0.01) && reloj.currentTime().asSeconds()<=3 && a>=0){
        getRenderer()->setColor(255,255,255,a);
        a+=2.8;
       trans.restart();
    }
    
    if(trans.currentTime().asSeconds()>(0.01) && reloj.currentTime().asSeconds()>=5 && a>0){
        
                getRenderer()->setColor(255,255,255,a);
                a-=2.8;
               trans.restart();
        }
    
    if(reloj.currentTime().asSeconds()>8) getRenderer()->setColor(0,0,0,0);
    
    if(reloj.currentTime().asSeconds() > 9 || gme::Keyboard::isKeyPressed(spaceKey)){        
      gme::Game::setCurrentScene("mainmenu");        
      reloj.restart();    
   }

     
}
    


splash::~splash(){


}

