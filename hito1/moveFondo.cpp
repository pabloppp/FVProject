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
    gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
    gme::GUI::tintColor = gme::GUI::red;
    
    gme::GUI::drawTexture(
        gme::Vector2(320,240), 
        gme::Vector2(100,500), 
        gme::GUI::TextureName("logo"), 
        gme::GUI::Origin::Center,
        gme::GUI::ScaleMode::ScaleToFit    
    );
    gme::GUI::contentColor = gme::GUI::white;
    gme::GUI::label(gme::Vector2(gme::Mouse::getPosition().x, gme::Mouse::getPosition().y).worldToScreen(), "MENU 1", gme::GUI::Origin::Center);
}

moveFondo::~moveFondo(){


}
